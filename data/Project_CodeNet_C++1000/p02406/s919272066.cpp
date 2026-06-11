#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    for(int i=1; i<=n; i++){
        if(i%3 == 0){
            cout << " " << i;
        }else{
            string s = to_string(i);
            for(auto c: s) if(c == '3'){
                cout << " " << i;
                break;
            }
        }
    }
    cout << endl;
    return 0;
}