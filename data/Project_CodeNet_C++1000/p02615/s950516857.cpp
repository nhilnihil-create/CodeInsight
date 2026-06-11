#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];

    sort(a.rbegin(),a.rend());
    ll s = a[0];
    ll mx = a[1];
    ll t =2;
    ll j = 1;
    for(int i=2;i<(int)a.size();++i)
    {
        s+= mx;
        t--;
        if(t==0)
        {
            mx = a[++j];
            t=2;
        }
    }
    cout<<s<<endl;


    return 0;
}