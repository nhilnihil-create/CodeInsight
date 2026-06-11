#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
typedef long long ll;
using namespace std;

string s;

int main(){
    cin >> s;
    int ans = 0;
    if(s.size() % 2 == 1 ){
        rep(i,(s.size()-1)/2){
            if(s[i] == s[s.size()-i-1]) continue;
            else{
                ans++;
            }
        }
    }
    else{
        rep(i,s.size()/2){
            if(s[i] == s[s.size()-1-i]) continue;
            else{
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}