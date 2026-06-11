#include<iostream>
#include<vector>
using namespace std;

long long n,k;
vector<long long> a;

bool C(long long x){
    long long num=0;
    for(int i=0;i<n;++i){
        num+=(a[i]+x-1)/x-1;
    }
    return num<=k;
}

int main(){
    cin>>n>>k;
    a.resize(n);
    for(long long i=0;i<n;++i) cin>>a[i];

    long long l=0,r=1e9+7;
    while(r-l>1){
        long long mid=(r+l)/2;
        (C(mid)?r:l)=mid;
    }

    cout<<r<<endl;
}