#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, o;
    cin>>n>>m>>o;
    if(n==m && n!=o)
        cout<<"Yes";
    else if(n==o && n!=m)
        cout<<"Yes";
    else if(m==o && m!=n)
        cout<<"Yes";
    else
        cout<<"No";
}
