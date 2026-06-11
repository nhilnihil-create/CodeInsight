#include<bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
void pass()
{
    ll k = 0,s = 0;
    int n;
    cin>>n;
    vector<int>a(n+1,0);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= n; j+=i)
        {
            a[j]++;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        s += (i*(ll)a[i]);;
    }

    cout<<s<<endl;
}
int main()
{
    ll n,m,k=0,s=0,l=0,t=0;
    pass();
}


