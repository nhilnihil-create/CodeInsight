#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    string s;
    cin >> s;
    ll n = s.size();
    ll ans = 1;
    bool flag = false;
    i = 1;
    while(i < n){
        if(!flag){
            if(s.at(i) != s.at(i-1)){
                ++ans;
                ++i;
            }else{
                if(i == n-1) break;
                flag = true;
                ++ans;
                i += 2;
            }
        }else{
            flag = false;
            ++ans;
            ++i;
        }
    }
    cout << ans << endl;
    return 0;
}