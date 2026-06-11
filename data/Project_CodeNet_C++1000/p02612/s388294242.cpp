#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,m;
    cin>>n;
    k=n%1000;
    if(k>0){
        m=1000-k;
    cout<<m<<endl;}
    else
        cout<<0<<endl;
}
