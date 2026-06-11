#include <iostream>
#include<vector>
#include<algorithm>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define rng(a) a.begin(),a.end()
using ll = long long;

using namespace std;



int main() {
    int n;
    cin>>n;
    vector<string>s(n);
    rep(i,n) {
        cin>>s[i];
        sort(rng(s[i]));
    }
    sort(rng(s));
    ll ans = 0;
    ll cnt = 1;
    rep(i,n) {
        if(s[i]!=s[i+1]) {
            ans += cnt*(cnt-1)/2;
            cnt = 1;
            continue;
        }
        cnt++;
    }
    cout<<ans<<endl;
    

    return 0;
}
