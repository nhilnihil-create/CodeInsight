#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
int main()
{
    int n,l,sum=0,num=1e9,num2;
    cin>>n>>l;
    rep(i,n){
        int a=i+l;
        sum+=a;
        if(num>abs(a-0)){
            num=abs(a-0);
            num2=a;
        }
    }
    cout<<sum-num2;
}