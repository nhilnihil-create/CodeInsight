#include<bits/stdc++.h>
using namespace  std;

int main(void)
{
    int n,k; cin>>n>>k;
    if(k==1) {cout<<0<<endl; return 0;}
    int cnt=n;
    for(int i=1;i<k;i++)
    {
        n--;
    }
    cout<<n-1<<endl;
     return 0;
}
