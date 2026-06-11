#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll N,K,Q;
    cin>>N>>K>>Q;
    long long a[N+1]={};
    long long b[N];
    long long mi=0;
    long long ma=0;
    for(long long i=0;i<Q;i++){
    cin>>ma;
    a[ma]++;}
    for(long long i=1;i<=N;i++){
    if(K-Q+a[i]>0){
    cout<<"Yes"<<endl;}
    else
    cout<<"No"<<endl;}}
