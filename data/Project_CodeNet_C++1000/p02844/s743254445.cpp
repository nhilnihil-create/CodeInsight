#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for(int i=0; i<=9; i++){
        for(int j=0; j<=9; j++){
            for(int k=0; k<=9; k++){
                bool flag1 = false;
                bool flag2 = false;
                for(int l=0; l<n; l++){
                    if(flag2 == true && s[l] - '0' == k){ ans += 1; break; };
                    if(flag1 == true && flag2 == false && s[l] - '0' == j) flag2 = true;
                    if(flag1 == false && s[l] - '0' == i) flag1 = true;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}