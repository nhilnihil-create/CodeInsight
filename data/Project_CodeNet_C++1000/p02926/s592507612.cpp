#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
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
    pair<double,pdouble> engine[N];
    rep(i,N) cin >> engine[i].second.first >> engine[i].second.second;
    rep(i,N) engine[i].first=atan2(engine[i].second.second,engine[i].second.first);
    sort(engine,engine+N);
    double ans=0;
    for(int i=0;i<N;i++){
        double dx=0,dy=0;
        for(int j=i;j<i+N;j++){
            dx+=engine[j%N].second.first;
            dy+=engine[j%N].second.second;
            double dis=sqrt(pow(dx,2)+pow(dy,2));
            ans=max(ans,dis);
        }  
    }
    cout << ans << endl;
}