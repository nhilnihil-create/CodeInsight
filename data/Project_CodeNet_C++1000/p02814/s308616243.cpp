#include <bits/stdc++.h>

#define int long long

using namespace std;

#ifdef LOCAL 
#include "/media/brayand/7801-B00D/debugger.h"
#else
template<typename... Args>
void db(Args... args){}
#endif

vector<int> arr[100];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    int mcm2 = 1;

    bool flai = true;

    for(int i = 0 ; i < N ; i++)
    {
    	int n;
    	cin >> n;
    	mcm2 = mcm2*n/__gcd(mcm2,n);
    	if(mcm2 > M)flai = false;
    	n /= 2;

    	int cont = 0;

    	while(n%2 == 0)
    	{
    		cont++;
    		n/=2;
    	}
    	arr[cont].push_back(n);
    }


    bool flag = false;

    int mcm = 1;

    int res = 1;

    for(int i = 0 ; i < 100 ; i++)
    {
    	if(arr[i].size() == N)
    	{
    		flag = true;
    		for(auto x : arr[i])
    		{
    			mcm = mcm*x/__gcd(mcm,x);
    			if(mcm > M)
    			{
    				flag = false;
    				break;
    			}
    		}
    		mcm *= (1ll<<i);
    		if(mcm > M)flag = false;

    		if(flai)
    		{
    			res += (M-mcm)/mcm2;
    		}
    	}
    }

    if(flag)cout << res << '\n';
    else cout << 0 << '\n';

    return 0;
}