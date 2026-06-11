#include<bits/stdc++.h>
#include<iostream>
#include<math.h>

using namespace std;

typedef long long int ll; 

int main(void)
{
	ll n;
	char arr[4001];
	cin >> n >> arr;

	ll r[4001],g[4001],b[4001];
	ll ri=0,gi=0,bi=0;

	for(ll i=0;i<strlen(arr);i++)
	{
		if(arr[i] == 'R')
			r[ri++] = i;
		else if(arr[i] == 'G')
			g[gi++] = i;
		else if(arr[i] == 'B')
			b[bi++] = i;
	}

	ll ans = ri*gi*bi;

	// for(ll i=0;i<strlen(arr);i++)
	// 	cout << i << ": " << arr[i] << endl;

	for(ll i=0;i<ri;i++)
	{
		// ll red = arr[r[i]];
		for(ll j=0;j<gi;j++)
		{
			ll idx_bigger = 2*max(r[i],g[j]) - min(r[i],g[j]);
			ll idx_smaller = 2*min(r[i],g[j]) - max(r[i],g[j]);
			ll idx_mid = r[i]+g[j]; // div by 2 check if float

			if(idx_bigger<n && binary_search(b,b+bi,idx_bigger))
			{	
				ans--;
				// cout << "bigger: " <<r[i] << " " << g[j] << " " << idx_bigger << endl;
			}
			if(idx_smaller>=0 && binary_search(b,b+bi,idx_smaller))
			{	
				ans--;
				// cout << "smaller: " <<r[i] << " " << g[j] << " " << idx_smaller << endl;

			}
			if(idx_mid%2==0 && binary_search(b,b+bi,idx_mid/2))
			{	
				ans--;
				// cout << "mid: " <<r[i] << " " << g[j] << " " << idx_mid/2 << endl;

			}
		}
	}
	cout << ans << endl;



	return 0;
}