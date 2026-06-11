#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    long long int ans=0;
    if(n%2==0)
    {
        n=n>>1;
        while(n>0)
        {
            ans+=n/5;
            n/=5;
        }
    }
    cout<<ans<<endl;
}