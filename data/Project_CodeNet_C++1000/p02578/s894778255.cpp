#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll n;cin>>n;
ll a[n];
ll sum = 0;
for(int i=0;i<n;i++)
    cin>>a[i];
for(int i=0;i<n-1;i++)
    if(a[i]>a[i+1])
        {sum+=(a[i]-a[i+1]);
        a[i+1]+=(a[i]-a[i+1]);}
    else
        continue;
cout<<sum<<endl;
return 0;}
