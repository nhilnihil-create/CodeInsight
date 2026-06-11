#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll t1,t2,a1,a2,b1,b2;cin>>t1>>t2>>a1>>a2>>b1>>b2;
    if(a1>b1){
        swap(a1,b1);
        swap(a2,b2);
    }
    ll a=a1*t1+a2*t2,b=b1*t1+b2*t2;
    if(a==b){
        cout<<"infinity"<<endl;
        return 0;
    }
    if(a>b){
        ll res=((b1-a1)*t1)/(a-b);
        res*=2;
        if(((b1-a1)*t1)%(a-b)!=0)res++;
        cout<<res<<endl;
    }else{
        cout<<0<<endl;
    }
}
