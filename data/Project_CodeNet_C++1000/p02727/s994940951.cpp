#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
#define MOD ((int)1e9+7)
#define N ((int)1e5+123)
void reads(string& x){ char kk[N]; scanf("%s",kk); x = kk;}

ll x,y,a,b,c,A[N],B[N],C[N], ans;
priority_queue<ll> pa,pb;
void solve(){
    scanf("%lld%lld%lld%lld%lld", &x,&y,&a,&b,&c);
    for(int i=0;i<a;i++){
        scanf("%lld",&A[i]);
    }
    for(int i=0;i<b;i++){
        scanf("%lld",&B[i]);
    }
    for(int i=0;i<c;i++){
        scanf("%lld",&C[i]);
    }
    sort(A,A+a,greater<ll>());
    sort(B,B+b,greater<ll>());
    sort(C,C+c,greater<ll>());

    for(int i=0;i<x;i++){
        pa.emplace(-A[i]);
    }
    for(int i=0;i<y;i++){
        pb.emplace(-B[i]);
    }
    for(int i=0;i<c;i++){
        if(-pa.top()<-pb.top()){
            if(C[i]>-pa.top()){
                pa.pop();
                pa.emplace(-C[i]);
            }
            else break;
        }
        else{
            if(C[i]>-pb.top()){
                pb.pop();
                pb.emplace(-C[i]);
            }
            else break;
        }
    }
    while(!pa.empty()){
        ans-=pa.top();
        pa.pop();
    }
    while(!pb.empty()){
        ans-=pb.top();
        pb.pop();
    }
    printf("%lld\n",ans);
}

int main(){
    ios_base::sync_with_stdio(0);
    int t = 1; //scanf("%d",&t);
    for(int caso=1;caso<=t;caso++){
        solve();
    }
}