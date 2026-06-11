#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long a[n+1];
    map<long long,long long>m;
    long long ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans+=m[a[i]-i];
        m[-a[i]-i]++;
    }
    cout<<ans<<endl;
    return 0;
}
