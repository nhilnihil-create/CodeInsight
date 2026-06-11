#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    ll n;
    cin >> n;
    ll ans=0;
    for(ll i=1; i<=n; i++)
        ans+=(ll)i*(n-i+1);
    for(ll i=1; i<=n-1; i++){
        ll u, v;
        cin >> u >> v;
        if(u>v)
            swap(u, v);
        ans-=(ll)u*(n-v+1);
    }

    cout << ans << endl;

	return 0;
}
