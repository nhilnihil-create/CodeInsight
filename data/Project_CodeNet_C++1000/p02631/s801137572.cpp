#include <bits/stdc++.h>

#define int long long

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> vect;

    for(int i = 0 ; i < N ; i++)
    {
    	int n;
    	cin >> n;
    	vect.push_back(n);
    }

    for(int x = 0 ; x < 31 ; x++)
    {
    	int c0 = 0, c1 = 0;
    	for(int i = 0 ; i < N ; i++)
    	{
    		if(vect[i]&(1<<x))c1++;
    	}

    	if(c1&1)
    	{
    		for(int i = 0 ; i < N ; i++)
			{
				vect[i] ^= (1<<x);
			}
    	}
    }

    for(int i = 0 ; i < N ; i++)
    {
    	cout << vect[i] << " ";
    }
    cout << '\n';

    return 0;
}