#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    for(int i=0; s[i]; i++){
        if(i%2 == 0){
            if(s[i] == 'L'){
                cout << "No\n";
                return 0;
            }
        }
        else{
            if(s[i] == 'R'){
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";

    return 0;
}
