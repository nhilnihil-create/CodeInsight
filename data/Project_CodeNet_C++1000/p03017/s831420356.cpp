#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b,c,d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    for(int i = min(a,b); i < max(c,d)-2; i++){
        if(s.substr(i,2) == "##"){
            cout << "No" << endl;
            return 0;
        }
    }
    if(c < d){
        cout << "Yes" << endl;
        return 0;
    }else{
        for(int i = b-2; i < d-1; i++){
            if(s.substr(i,3) == "..."){
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
    }
    return 0;
}


