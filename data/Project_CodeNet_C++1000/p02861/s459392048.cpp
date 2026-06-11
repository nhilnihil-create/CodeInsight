#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

double fact( double n)
{
    if (n<=1) {return 1;}
    else {return n*fact(n-1);}
}

int main() {
    double l,m,n,i,sum=0,p,q,r,j; vector<double>a,x,y; cin>>n;
    for(i=0;i<n;i++)
    { cin>>l>>m; x.pb(l); y.pb(m); a.pb(i);}
    l=fact(n);
    for(j=0;j<l;j++)
    {
        for(i=0;i<n-1;i++)
        { p=a[i];q=a[i+1];
            r=(x[p]-x[q])*(x[p]-x[q])+(y[p]-y[q])*(y[p]-y[q]);
            sum+=sqrt(r);
        }
        next_permutation(a.begin(),a.end());
    }
    cout<<fixed<<setprecision(10)<<(sum/l);
	return 0;
}