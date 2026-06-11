#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
int main(){
    int n;
    ll ans=0;
    cin >> n;
    string s;
    map<string,int> cnt;
    rep(i,n){
        cin >> s;
        sort(s.begin(),s.end());
        if(cnt[s]!=0)ans+=cnt.at(s);
        cnt[s]++;
    }
    cout << ans;
    return 0;
}