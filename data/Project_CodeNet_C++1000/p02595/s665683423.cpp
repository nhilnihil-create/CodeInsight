#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, d, ans = 0;
				
				cin >> n >> d;
			 while(n--)
				{
				  long long int x, y;

      cin >> x >> y;
								
      long long int dist = x * x + y * y;

      if(dist <= d * 1LL * d) ans++;
    }
				

    cout << ans << "\n";
}