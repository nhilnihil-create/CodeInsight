#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main( )
{
    int cnt=0;
    int l,w,n;
    cin>>l>>w>>n;
    for(int i=l;i<=w;i++)
    {
        if(i%n==0) ++cnt;
    }
    cout<<cnt<<endl;
}