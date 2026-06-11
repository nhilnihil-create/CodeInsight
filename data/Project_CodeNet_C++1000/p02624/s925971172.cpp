#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin>>n;
    long long ans=0;
    for(long long i=1;i<=n;i++){
        long long l=i;
        long long h=(n/i);
        h*=i;
        long long c=h/i - l/i;
        c+=1;
        ans+=(c*(l+h))/2;
    }
    cout<<ans<<endl;
}

int main()
{
    long long t;
    solve();
}