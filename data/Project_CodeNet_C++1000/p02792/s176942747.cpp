#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int num(long long n)
{
    ll t,p;
    t=((int)(log10(n)));
    p=(int)(n/(int)(pow(10,t)));
    return p;
}
int main()
{
    ll N,i,j,s,k=0;
    ll a[10][10]={0};
    cin>>N;
    for(i=1;i<=N;i++){
        if(i%10==0) continue;
        else{
            s=num(i);
            a[s][i%10]++;
        }
    }
    for(i=1;i<=9;i++){
        for(j=1;j<=9;j++){
            k+=a[i][j]*a[j][i];
        }
    }
    cout<<k<<endl;
}