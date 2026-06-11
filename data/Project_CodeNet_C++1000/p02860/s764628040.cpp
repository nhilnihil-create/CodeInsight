#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n >> s;
    if(n % 2 == 1){
        cout << "No" << endl;
        return 0;
    }
    for(int i = 0; i < n / 2; i++){
        if(s.at(i) != s.at(i + n / 2)){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}