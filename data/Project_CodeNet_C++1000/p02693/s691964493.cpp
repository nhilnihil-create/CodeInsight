#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k;cin>>k;
    int a,b;cin>>a>>b;
    int x=0;
    for(int i=a;i<=b;i++)if(i%k==0)x=1;

    if(x==0)cout<<"NG"<<endl;
    else cout<<"OK"<<endl;



}
