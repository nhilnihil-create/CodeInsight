#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
#define fi(i, n) for( int i=0 ; i<n ; i++ )
#define f(i, a, b) for( int i=a ; i<b ; i++ )
#define vi vector<int>
#define pb push_back
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

}

int main()
{
    int n;
    cin>>n;
    if(n>81)
    {
        cout<<"No";
        return 0;
    }
    vi v;
    f(i,1,10)
    {
        f(j,i,10)
        {
            v.pb(i*j);
        }
    }
    vi :: iterator it;
    it = find(v.begin(),v.end(),n);
    if(it==v.end())
    {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes";

}
