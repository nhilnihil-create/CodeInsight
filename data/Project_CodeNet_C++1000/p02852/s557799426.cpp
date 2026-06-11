#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n,m;cin>>n>>m;
    string s;cin>>s;
    reverse(s.begin(),s.end());
    vector<int> a(n+1,-1);
    int tmp=0;
    rep(i,n+1){
        if(s[i]=='0')tmp=i;
        a[i]=tmp;
    }
    tmp=0;
    vector<int> b;
    while(tmp<n){
        if(tmp+m>=n){
            b.push_back(n-tmp);
            break;
        }
        int nx=a[tmp+m];
        if(nx==tmp){
            cout<<-1<<endl;
            return 0;
        }
        b.push_back(nx-tmp);
        tmp=nx;
    }
    reverse(b.begin(),b.end());
    rep(i,b.size())cout<<b[i]<<" ";
    cout<<endl;
}