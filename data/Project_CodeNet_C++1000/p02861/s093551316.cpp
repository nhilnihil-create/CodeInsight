#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ff first
#define ss second
ll fact(ll n)
{
    if(n==0)
        return 1;
    return fact(n-1)*n;
}
double dist(pair<ll,ll> a , pair<ll,ll> b)
{
    return sqrt((a.ff-b.ff)*(a.ff-b.ff) + (a.ss-b.ss)*(a.ss-b.ss));
}
int main()
{
    ll n;
    cin >> n;
    double sum = 0;
    pair<ll,ll> a[n];
    for(ll i=0;i<n;i++)
    {
        cin >> a[i].first;
        cin >> a[i].second;
       
    }
    sort(a,a+n);
    int cnt = 0;
    do
    {
        cnt++;
        for(ll i=0;i<n-1;i++)
        {
            sum += dist(a[i],a[i+1]);
        }
        
    } while (next_permutation(a,a+n));
    
    // cout << sum << " " << fact(n)<<endl;
    double ans = sum/fact(n);
    printf("%0.12lf",ans);
    return 0;
}
