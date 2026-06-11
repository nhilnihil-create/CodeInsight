#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define vii vector<int>
#define vll vector<ll>
#define mat vector<vector<ll>>
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define sz(x) (ll) (x).size()
#define pq priority_queue<ll>
#define pqg priority_queue<ll,vector<ll>,greater<ll>>
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end())
#define int ll
using namespace std;
const ll INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
const ll mod = 998244353;
const ll MAX = 1100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[4] ={1,0,-1,0} , dy[4] ={0,1,0,-1};

template<class T> 
inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> 
inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

struct Timer{
    chrono::system_clock::time_point start, end;
    Timer(){ start = chrono::system_clock::now(); }
    ~Timer(){
        end = chrono::system_clock::now();
        auto msec = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cerr<<"time : "<<msec<<" ms"<<endl;
    }
};


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Timer TM;


    ll N;
    cin>>N;
    ll n=(ll)pow(2,N);
    ll s[300010];
    rep(i,n){
        cin>>s[i];
    }
    sort(s,s+n);
    reverse(s,s+n);
    vll t;
    map<ll,ll> mp,cnt;
    rep(i,n){
        // cout<<s[i]<<" ";
        if(mp[s[i]]==0) t.pb(s[i]);
        mp[s[i]]++;
    }
    sort(all(t));
    // cout<<endl;
    vll v;
    v.pb(s[0]);
    cnt[s[0]]++;
    rep(i,N){
        ll m=v.size();
        sort(all(v));
        reverse(all(v));
        // rep(j,m){cout<<v[j]<<"=";} cout<<endl;
        rep(j,m){
            ll k=LB(t,v[j]-1);
            // cout<<i<<" "<<j<<" "<<t[k]<<" "<<v[j]<<" "<<endl;
            if(k==(ll)t.size()) k--;
            if(k<0){
                cout<<"No"<<endl;
                return 0;
            }
            if(t[k]>=v[j]) k--;
            if(k<0){
                cout<<"No"<<endl;
                return 0;
            }
            if(cnt[t[k]]==mp[t[k]]){
                t.erase(t.begin()+k);
                k--;
            }
            // cout<<i<<" "<<j<<" "<<k<<endl;
            if(k<0){
                cout<<"No"<<endl;
                return 0;
            }
            if(cnt[t[k]]<mp[t[k]]){
                // cerr<<"#!"<<endl;
                cnt[t[k]]++;
                v.pb(t[k]);
                continue;
            }
            else {
                bool ok=false;
                while(k>=0){
                    k--;
                    if(cnt[t[k]]<mp[t[k]]){
                        cnt[t[k]]++;
                        v.pb(t[k]);
                        ok=true;
                        if(cnt[t[k]]==mp[t[k]]){
                            t.erase(t.begin()+k);
                        }
                        break;
                    }
                }
                if(!ok){
                    // cout<<i<<" "<<j<<endl;
                    cout<<"No"<<endl;
                    return 0;
                }
            }

        }
    }
    // rep(j,(ll)v.size()){
    //     cerr<<v[j]<<"~";
    // }
    // cout<<endl;
    for(auto i: mp){
        // cout<<i.fi<<"$"<<cnt[i.fi]<<" "<<i.sc<<endl;
        if(cnt[i.fi]!=i.sc){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
