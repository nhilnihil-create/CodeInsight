#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;

int main(){
    char s[101];
    cin >> s;

    int n = strlen(s);
    rep(i,n){
        if( i % 2 == 0){
            if(s[i] == 'L'){
                cout << "No" << endl;
                return 0;
            }
        }
            else
            {
                if(s[i] == 'R'){
                    cout << "No" << endl;
                    return 0;
                }
            }
    }
    cout << "Yes" << endl;

    return 0;
}