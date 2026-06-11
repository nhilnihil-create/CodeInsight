#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i,n) for(ll i=0;i<n;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define fi first
#define se second
#define endl "\n"

template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){int len=d.size();rep(i,len){s<<d[i];if(i<len-1) s<<" ";}return s;}
template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){int len=d.size();rep(i,len){s<<d[i]<<endl;}return s;}
template<typename T> ostream& operator<<(ostream& s,const set<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){s<<"{"<<endl;for(auto itr=m.begin();itr!=m.end();++itr){s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;}s<<"}"<<endl;return s;}

const ll mod=1e9+7;
const ll inf=1e17;
const int INF=1e9;
const double PI=acos(-1);
const double EPS=1e-10;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    if((n-1)*(n-2)/2<k){
        cout<<-1<<endl;
        return 0;
    }
    vector<vector<int>> g(n,vector<int>(n,-1));
    FOR(i,1,n){
        g[0][i]=g[i][0]=1;
    }
    int cnt=(n-1)*(n-2)/2-k;
    FOR(i,1,n)FOR(j,i+1,n){
        if(cnt){
            g[i][j]=g[j][i]=1;
            cnt--;
        }
    }
    int m=0;
    rep(i,n)rep(j,n) if(g[i][j]==1) m++;
    cout<<m/2<<endl;
    rep(i,n)FOR(j,i+1,n){
        if(g[i][j]==1){
            cout<<i+1<<' '<<j+1<<endl;
        }
    }
}