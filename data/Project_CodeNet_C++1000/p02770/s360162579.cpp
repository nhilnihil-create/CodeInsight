#include<bits/stdc++.h>
using namespace std;
//#include<boost/multiprecision/cpp_int.hpp>
//using boost::multiprecision::cpp_int;

#define int long long
#define cint cpp_int
#define endl "\n"
#define REP(i,a,n) for(int i=a;i<n;++i)
#define REPR(i,a,n) for(int i=a;i>n;--i)
#define RUP(a,b) (((a)+(b)-1)/(b))
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define MOD 1000000007
#define INF LLONG_MAX/2
#define PI acos(-1.0)

typedef long long ll;
typedef pair<int,int> Pii;
typedef tuple<int,int,int> Tiii;
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef vector<Pii> VPii;
typedef vector<string> Vs;
typedef priority_queue<int> PQi;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
void vout(Vi &v){for(int i=0;i<(v).size();i++) cout<<v[i]<<" ";cout<<endl;}
void vvout(VVi &v){for(int i=0;i<(v).size();i++) vout(v[i]);}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}
int mypow(int x, int n, int m){if(n==0)return 1;if(n%2==0)return mypow(x*x%m,n/2,m);else return x*mypow(x,n-1,m)%m;}
int digit(int k,int i){string s = to_string(k);return s[s.size()-i]-'0';}
void uniq(Vi &v){sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());}
int ctoi(char c){if(c>='0'&&c<='9'){return c-'0';}return 0;}
int leng(int n){string s=to_string(n); return s.size();}
int lesscount(int x,Vi &a){return lower_bound(a.begin(),a.end(),x)-a.begin();} //vector aにおけるx未満の数の個数
int orlesscount(int x,Vi &a){return upper_bound(a.begin(),a.end(),x)-a.begin();} //vector aにおけるx以下の数の個数
int morecount(int x,Vi &a){return a.size()-orlesscount(x,a);} //vector aにおけるxより大きい数の個数
int ormorecount(int x,Vi &a){return a.size()-lesscount(x,a);} //vector aにおけるx以上の数の個数
int count(int x,Vi &a) {return upper_bound(ALL(a),x)-lower_bound(ALL(a),x);}
Vi accum(Vi &v){Vi ret((v).size()+1);REP(i,0,(v).size()) ret[i+1]=ret[i]+v[i];return ret;}
bool comp(Pii a,Pii b){
    if(a.second != b.second) return a.second<b.second;
    else return a.first<b.first;
}


signed main(){
    int k,q;
    cin>>k>>q;
    Vi d(k);
    REP(i,0,k){
        cin>>d[i];
    }

    REP(Q,0,q){
        int n,x,m;
        cin>>n>>x>>m;
        x %= m;
        Vi newd(k);
        REP(i,0,k){
            newd[i]=d[i]%m;
        }
        Vi num0(k+1);
        REP(i,1,k+1){
            if(newd[i-1]==0) num0[i]=num0[i-1]+1;
            else num0[i]=num0[i-1];
        }
        Vi sumd=accum(newd);

        int num0s=num0[k];
        int sum=sumd[k];

        int allsum=x+((n-1)/k)*sum+sumd[(n-1)%k];
        int count0 = ((n-1)/k)*num0s + num0[(n-1)%k];
        // vout(num0);
        // vout(sumd);
        // cout<<allsum<<" "<<num0s<<endl;
        cout<<(n-1)-allsum/m-count0<<endl;
    }
    return 0;
}
