#include<bits/stdc++.h>
using namespace std;
int serch(int i,int j,int n)
{
    if(!n&&!j)return 1;
    else if(i==10||!n)return 0;
    return serch(i+1,j-i,n-1)+serch(i+1,j,n);
}
int main()
{
    int n,s;
    while(cin>>n>>s&&n!=0)cout<<serch(0,s,n)<<endl;
}