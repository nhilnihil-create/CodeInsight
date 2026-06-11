#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
    ll n;cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i){
        cin>>a[i]>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(n&1){
        int m=n/2;
        cout<<b[m]-a[m]+1<<endl;
    }else{
        int m=n/2;
        cout<<(b[m]+b[m-1])-(a[m]+a[m-1])+1<<endl;
    }
}