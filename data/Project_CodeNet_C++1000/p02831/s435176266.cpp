//Try until you reach your goal
#include <bits/stdc++.h>
using namespace std;
# define ll long long
# define endl "\n"
# define str string
# define vll vector<ll>
# define pb push_back
# define mll map<ll,ll>
# define mp make_pair
# define ff first
# define ss second
# define pll pair<ll,ll>
# define f(x,y) for(int x=0;x<y;x++)
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll x,y;
    cin>>x>>y;
    ll k=__gcd(x,y);
    ll k1=x*y;
    ll k2=k1/k;
    cout<<k2;
    return 0;
}