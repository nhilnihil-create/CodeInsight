#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,double> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse

int b_search(vector<int> &v,int n) {
    int l=-1,r=v.size(),mid=(r+l)/2;
    while(r-l>1) {
        if(v[mid] >= n) r = mid;
        else l = mid;
    }
    return r;
}

int main() {
    string s,t;cin>>s>>t;
    vector<int> dic[26];
    rep(i,s.size()) {
        dic[s[i]-'a'].push_back(i);
    }
    ll cnt=0,pos=0;
    rep(i,t.size()) {
        if(dic[t[i]-'a'].size()==0) {
            cout<<-1<<endl;
            return 0;
        }
        if(pos > dic[t[i]-'a'][(dic[t[i]-'a'].size()-1)]) {
            cnt++;
            pos = dic[t[i]-'a'][0] + 1;
        } else {
            // cout<<t[i]<<" "<<b_search(dic[t[i]-'a'],pos)<<endl;
            // pos = dic[t[i]-'a'][b_search(dic[t[i]-'a'],pos)] + 1;
            // pos = dic[t[i]-'a'][int(lower_bound(dic[t[i]-'a'].begin(),dic[t[i]-'a'].end(),pos))] + 1;
            auto it = lower_bound(dic[t[i]-'a'].begin(),dic[t[i]-'a'].end(),pos);
            pos = *it + 1;
        }
        // cout<<"pos "<<pos<<endl;
    }
    ll ans = cnt * s.size() + pos;
    cout<<ans<<endl;
}