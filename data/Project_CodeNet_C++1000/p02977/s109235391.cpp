#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
#define INF (1<<30)
#define LINF (1LL<<60)
#define endl "\n"
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
typedef unsigned long long int ull;
typedef long long lint;

int main(void){
    int N;
    cin >> N;
    if(log2(N)==(int)log2(N)) cout << "No" << endl;
    else{
        cout << "Yes" << endl;
        cout << 1 << " " << 2 << endl;
        cout << 2 << " " << 3 << endl;
        cout << 3 << " " << N+1 << endl;
        cout << N+1 << " " << N+2 << endl;
        cout << N+2 << " " << N+3 << endl;
        int p=4;
        while(p<N){
            cout << 1+N << " " << p << endl;
            cout << p << " " << p+1 << endl;
            cout << 1+N << " " << p+1+N << endl;
            cout << p+N << " " << p+N+1 << endl;
            p+=2;
        }
        if(p==N){
            int ans=log2(p);
            ans=pow(2,ans);
            cout << p << " " << ans << endl;
            ans=ans^1^p;
            ans+=N;
            if(ans==3+N) cout << 3 << " " << p+N << endl;
            else cout << ans << " " << p+N << endl;
        }
    }
}