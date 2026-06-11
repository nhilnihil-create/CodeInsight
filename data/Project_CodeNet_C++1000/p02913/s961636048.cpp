#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;
const ull B=1000000007;//ハッシュの基数

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int left=0,right=n;
    while(right-left>1){
        int mid=(right+left)/2;
        ull t=1;
        for(int i=0;i<mid;i++) t*=B;
        set<ull> st;
        queue<ull> que;
        ull sh=0;
        for(int i=0;i<mid;i++) sh=sh*B+s[i];
        bool ok=0;
        for(int i=0;i+mid<=n;i++){
            if(st.count(sh)){
                ok=1;
                break;
            }
            que.push(sh);
            if(i>=mid-1){
                ull v=que.front();
                que.pop();
                st.insert(v);
            }
            if(i+mid<n) sh=sh*B+s[i+mid]-s[i]*t;
        }
        if(ok) left=mid;
        else right=mid;
    }
    cout<<left<<endl;
}