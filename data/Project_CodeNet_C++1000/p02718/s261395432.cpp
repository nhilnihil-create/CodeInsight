#include <iostream>
#include <string>
#include <cmath> 
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <numeric> 
#include <iomanip>
#include <map> 
#include <stack>
#include <sstream>
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
const int MAX = 1e6;
long long max(long long a, long long b) { if (a > b)return a; else return b; }
long long min(long long a, long long b) { if (a < b)return a; else return b; }
const int MAXN = 1000000 + 30;
int a[MAXN];


  		     		    	   				   	

int main()
{
	
		ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
		ld size, m;
		std::cin >> size>>m;
		std::vector <ld> v(size);
		for (ld i = 0; i < v.size(); i++)
		{
			std::cin >> v[i];
		}
		ld cnt = 0;
		ld k = 1 / (4 * m);
		ll d = std::accumulate(v.begin(), v.end(), 0);
			
			for (ld i = 0; i < v.size(); i++)
			{
				ld f = v[i] / d;
				if (f >= k)
				{
					cnt++;
				}
			}
			if (cnt >= m)
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}

		/*for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == k)
			{
				cout << "Yes" << endl;
			}
			else 
			{
				cout << "No" << endl;
				
			}
		
		}*/
			return 0;
	
}





	

  

