#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> l_l;
typedef pair<int , int> i_i;
typedef vector<ll> vel;
typedef vector<int> vei;
typedef vector<char> vec;
typedef vector<bool> veb;
typedef vector<string> ves;
typedef vector<vector<ll>> ve_vel;
typedef vector<vector<int>> ve_vei;
typedef vector<vector<char>> ve_vec;
typedef vector<vector<bool>> ve_veb;
typedef vector<vector<string>> ve_ves;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define rep2(i,n) for(int i=2;i<(int)(n);i++)
#define repk(i,k,n) for(int i=k;i<(int)(n);i++)
#define fs first
#define sc second
#define pub push_back
#define pob pop_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define maxel(a) *max_element(all(a))
#define minel(a) *min_element(all(a))
#define acc accumulate
#define EPS (1e-7)
//#define INF (1e9)
#define PI (acos(-1))
#define mod (1000000007)
typedef long long int64;
const int64 INF = 1LL << 58;
#define dame { puts("-1"); return 0;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    int n; cin>>n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    bool nega = false, posi = false;
    if(a[0]<0)nega=true;
    if(a[n-1]>=0)posi = true;

    if(posi&&nega){
        vector<int> po, ne;
        ll ans = 0;
        rep(i,n){
            if(a[i]>=0)po.push_back(a[i]);
            else ne.push_back(a[i]);
            ans += abs(a[i]);
        }
        cout<<ans<<endl;
        while(po.size()>1){
            cout<<ne[0]<<" "<<po.back()<<endl;
            ne[0]-=po.back();
            po.pop_back();
        }
        while(ne.size()){
            cout<<po[0]<<" "<<ne.back()<<endl;
            po[0]-=ne.back();
            ne.pop_back();
        }
        return 0;
    }

    else if(posi){
        ll ans = 0;
        rep(i,n-1)ans+=a[i+1];
        cout<<ans-a[0]<<endl;
        rep(i,n-2){
            cout<<a[0]<<" "<<a[i+1]<<endl;
            a[0]-=a[i+1];
        }
        cout<<a[n-1]<<" "<<a[0]<<endl;
        return 0;
    }
    
    else {
        ll ans = 0;
        reverse(a.begin(), a.end());
        rep(i,n-1)ans-=a[i+1];
        cout<<ans+a[0]<<endl;
        rep(i,n-1){
            cout<<a[0]<<" "<<a[i+1]<<endl;
            a[0]-=a[i+1];
        }
        return 0;
    }
    return 0;
}