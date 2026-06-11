#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int m,d;cin>>m>>d;
    int res=0;
    for(int i=1;i<=d;i++){
        int x=i%10,y=i/10;
        if(x>=2&&y>=2&&x*y>=1&&x*y<=m){
            //cout<<x<<" "<<y<<endl;
            res++;
        }
    }
    cout<<res<<endl;
}