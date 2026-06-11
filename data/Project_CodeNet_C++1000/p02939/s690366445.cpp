#include <bits/stdc++.h>
#define rep(i, a, n) for(ll i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    int ans = 0;
    bool flag = false;
    rep(i, 0, s.size()){
        if(flag){
            ans++; flag = false;
        }
        else if(s[i] != s[i+1]){
            ans++;
        }
        else{
            ans++;
            flag = true;
            i++;
        }
        
    }
    cout << ans << endl;
    return 0;
}
