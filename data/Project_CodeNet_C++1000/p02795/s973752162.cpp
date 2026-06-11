#include<bits/stdc++.h>

using namespace std;

int main()
{
    int h,w,n;
    cin>>h>>w>>n;
    int tmp=max(h,w);
    cout<<(n+tmp-1)/tmp<<'\n';
}