#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int a,b;cin>>a>>b;
    for(int i=0;i<=10000;i++){
        if(floor(i*0.08)==a&&floor(i*0.1)==b){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}
