#include <bits/stdc++.h>

using namespace std;

//FILE *fi=freopen("1.txt","r",stdin);

long long n,k,d;

void process()
{
    long long l=min(k,n/d);
    k-=l;
    long long x=n-l*d;
    if (k%2==0) cout<<x;
    else cout<<d-x;
}

int main()
{
    cin>>n>>k>>d;
    if (n<0) n=-n;
    process();
    return 0;
}
