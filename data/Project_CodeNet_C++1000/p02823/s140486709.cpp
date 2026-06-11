#include <bits/stdc++.h>

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
ll n,a,b;
cin>>n>>a>>b;
ll cnt=0;


if((b-a)%2==0){
    cnt+=(b-a)/2;
}
else{
    if(a-1<n-b){
        cnt+=a-1+1;
        cnt+=((b-(a-1+1))-1)/2;
    }
    else{
        cnt+=n-b+1;
        cnt+=(n-(a+(n-b+1)))/2;
    }
}
cout<<cnt<<endl;
return 0;
}