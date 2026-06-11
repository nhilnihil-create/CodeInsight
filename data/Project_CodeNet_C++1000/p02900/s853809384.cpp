#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
vector<long long int> factors(long long int n) 
{
    vector<long long int> f;
    for (long long int x = 2; x*x <= n; x++) 
    {
        if (n%x == 0) 
        {

            f.push_back(x);
            while(n%x==0)
            {

                n /= x;
            }
        }
    }
    if (n > 1) 
        f.push_back(n);
    return f;
}
int main()
{
    ll a,b;
    cin >> a >> b;
    vector<ll> aprime;
    vector<ll> bprime;
    ll anum=a;
    ll bnum=b;
    vector<ll>facta=factors(a);
    vector<ll>factb=factors(b);
    sort(facta.begin(),facta.end());
    sort(factb.begin(),factb.end());


   /* for(ll i=0;i<facta.size();i++)
    {
        cout << facta[i]<<" ";
    }
    cout << "\n";
    for(ll i=0;i<factb.size();i++)
    {
        cout << factb[i];
    }*/
    ll count=0;
    for(ll i=0;i<facta.size();i++)
    {
        for(ll j=0;j<factb.size();j++)
        {
            if(facta[i]==factb[j])
            {
                count++;
            }
        }
    }
    cout << count+1;
}
