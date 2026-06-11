#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll ansmod = 1000000007;

ll dp[100010] = {0};
ll ruizyou(ll a, ll b)
{
	ll res = a;
  	ll place = 1;
  	while(b > 1)
    {
  		if(b % 2 == 0)
    	{
    		res *= res;
      		b /= 2;
    	}
      	else
        {
        	place *= res;
          	b--;
        }
      	res %= ansmod;
      	place %= ansmod;
    }
  	return (res * place) % ansmod;
}

int main ()
{
	int n, k;
  	cin >> n >> k;
  	ll kosu[100010];
  	for(int i = 1; i <= k; i++)
    {
    	kosu[i] = ruizyou(k / i, n);
    }
  	for(int i = k; i > 0; i--)
    {
    	dp[i] = kosu[i];
      	for(int j = 2; j * i <= k; j++)
        {
        	dp[i] -= dp[j * i];
          	dp[i] %= ansmod;
        }
    }
  	ll ans = 0;
  	for(int i = 1; i <= k; i++)
    {
    	ans += i * dp[i];
      	ans %= ansmod;
    }
  	cout << ans % ansmod << endl;
  	}
