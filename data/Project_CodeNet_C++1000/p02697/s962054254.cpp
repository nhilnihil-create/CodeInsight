/* Isn't passion overrated?*/

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define mod 1000000007
using namespace std;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll se = n, fi = 1;
    ll j = 1;
    ll flag = 1;
    for(ll i = 0; i < k; i++){
    cout<<fi++<<" "<<se--<<endl;
    if(flag && (se-fi) <= n/2 && n%2 == 0)
    {
        flag = 0;
        se--;
    }
    }
    return 0;
}
