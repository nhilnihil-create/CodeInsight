#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    cin>>N;
    long long a[N];
    long long b[N];
    long long mi=0;
    long long ma=0;
    for(long long i=0;i<N;i++){
    cin>>a[i];
    cin>>b[i];}
    sort(a,a+N);
    sort(b,b+N);
    if(N%2==1){
    mi=a[(N-1)/2];
    ma=b[(N-1)/2];
    cout<<ma-mi+1<<endl;}
    else{
    mi=a[N/2]+a[N/2-1];
    ma=b[N/2]+b[N/2-1];
    cout<<(ma-mi)+1<<endl;}}
