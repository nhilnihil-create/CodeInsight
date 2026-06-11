#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;

    ll k;
    cin >> k;
    
    int len = s.length();

    ll ans = 0;
    int cou = 0;
    for(int i = 0; i < len - 1; i++){
        if(s[i] == s[i + 1]){
            cou++;
        }
    }

    if(cou == len - 1){
        ans = len * k;
        ans /= 2;
    }else{
        if(s[0] == s[len - 1]){
            int a = 1;
            for(int i = 0; i < len - 1; i++){
                if(s[i] == s[i + 1]){
                    a++;
                }else{
                    break;
                }
            }
            int b = 1;
            for(int i = len - 1; i > 0; i--){
                if(s[i] == s[i - 1]){
                    b++;
                }else{
                    break;
                }
            }

            for(int i = 0; i < len - 1; i++){
                if(s[i] == s[i + 1]){
                    s[i + 1] = '?';
                    ans++;
                }
            }
        
            ans *= k;
            ll t = a / 2;
            t += b / 2;
            t -= (a + b) / 2;
            t *= (k - 1);
            ans -= t;

        }else{
            for(int i = 0; i < len - 1; i++){
                if(s[i] == s[i + 1]){
                    s[i + 1] = '?';
                    ans++;
                }
            }
            ans *= k;
        }
    }

    cout << ans << endl;
}