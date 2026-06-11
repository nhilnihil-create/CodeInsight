#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define REP(i,a,n) for(int i=a;i<n;++i)
#define REPR(i,a,n) for(int i=a;i>n;--i)
#define RUP(a,b) ((a+b-1)/(b))
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define MOD 1000000007
#define INF LLONG_MAX/2

typedef long long ll;
typedef pair<int,int> Pii;
typedef tuple<int,int,int> Tiii;
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef vector<Pii> VPii;
typedef vector<string> Vs;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> void YesNo(T a) {cout<<(a?"Yes":"No")<<endl;}
template<class T> void YESNO(T a) {cout<<(a?"YES":"NO")<<endl;}
void vin(Vi &v){REP(i,0,(v).size()) cin>>v[i];}
void vin(Vi &v,Vi &v2){REP(i,0,(v).size()) cin>>v[i]>>v2[i];}
void vout(Vi &v){for(int i=0;i<(v).size();i++) cout<<v[i]<<" ";cout<<endl;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}
void uniq(Vi &v){sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());}
int ctoi(char c){if(c>='0'&&c<='9'){return c-'0';}return 0;}
void accum(Vi &v){REP(i,1,(v).size()) v[i]+=v[i-1];}
bool comp(Pii a,Pii b){
    if(a.second != b.second) return a.second<b.second;
    else return a.first<b.first;
}

signed main(){cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    int n,border=-1;
    cin>>n;
    Vi a(n);
    vin(a);

    sort(ALL(a));
//    vout(a);
    REP(i,0,n){
        if(a[i]>0){
            border=i;
            break;
        }
    }
    if(border==0) border=1;
    if(border==-1) border=n-1;
    int left=a[0],right=a[n-1];
    REP(i,border,n-1){
        left -= a[i];
    }
    REP(i,1,border){
        right -= a[i];
    }
//    cout<<right<< " "<<left<<endl;
    cout<<right-left<<endl;

    int cleft=a[0],cright=a[n-1];
    REP(i,border,n-1){
        cout<<cleft<<" "<<a[i]<<endl;
        cleft -= a[i];
    }
    REP(i,1,border){
        cout<<cright<<" "<<a[i]<<endl;
        cright -=a[i];
    }
    cout<<cright<<" "<<cleft<<endl;
    return 0;
}
