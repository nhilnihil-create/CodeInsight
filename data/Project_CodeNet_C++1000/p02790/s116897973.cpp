#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int main()
{
    int a,b;
    cin>>a>>b;
    if(a<b) rep(i,b) cout<<a;
    if(b<=a) rep(i,a) cout<<b;
}