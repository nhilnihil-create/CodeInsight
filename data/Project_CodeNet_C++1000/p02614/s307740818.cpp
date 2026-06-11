#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0);\
cin.tie(0);\
cout.tie(0);
#define ll long long   
#define endl '\n'  
using namespace std;
const int N = 100+ 5;
int  n, m, k,r = 0, b = 0;
int main()
{
	IO
		cin >> n >> m >> k; 
	char  arr[N][N]; 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
		
		
	}
	int  way1 = (1 << n);
	int  way2 =  (1 << m);
	int  ans = 0; 

	for(int  mask = 0 ;mask < way1 ;mask++)
	{
		for (int mask2 = 0; mask2 < way2; mask2++)
		{
			int  cur = 0;
			for (int i = 0; i < n; i++)
			{
				if ((mask&(1 << i)))continue; 
				for (int j = 0; j < m; j++)
				{
					if ((mask2&(1 << j)))continue; 
					if (!(mask & (1 << i)) && !(mask2 & (1 << j)))
					{
						if(arr[i][j]!='.')
						cur++;
					}
				}
			}
			if (cur == k)
				ans++; 

		}
		
    }
	cout << ans << "\n"; 

}