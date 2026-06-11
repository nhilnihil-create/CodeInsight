#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    long long a[n+1],sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n-k;i++){
        sum+=a[i];
    }
    cout<<sum<<endl;
}