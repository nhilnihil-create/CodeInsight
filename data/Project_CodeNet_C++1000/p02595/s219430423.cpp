#include<bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int ll;
typedef vector<pair<ll,ll> > vpl;
typedef vector<pair<int,int> > vpi;
typedef vector<ll> vec;
typedef map<ll,ll> mp;
ll GCD(ll a,ll b)
{
    if(a == 0)
    {
        return b;
    }
    return GCD(b%a,a);
}
int main()
{
    FastIO;
    int q = 1;
    //cin >> q;
    while(q--)
    {
        int n,d;
        cin >> n >> d;
        ll ara[n][2];
        for(int i =0;i<n;i++)
        {
            cin >> ara[i][0] >> ara[i][1];
        }
        int c = 0;
        for(int i =0;i<n;i++)
        {
            double x = sqrt((ara[i][0]*ara[i][0])+(ara[i][1]*ara[i][1]));
//            cout << x << endl;
            if(x <= d)
            {
                c++;
            }
        }
        cout << c << endl;
    }
}


