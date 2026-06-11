#include <bits/stdc++.h>
using namespace std;
long long n10 = 1, n9 = 1, n8 = 1, ans, l= 1000000007, n;
int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++) 
	{
        n10 = n10 * 10 % l;
        n9 = n9 * 9 % l;
        n8 = n8 * 8 % l;
    }
 
    ans = n10 - (n9 * 2 - n8);
    
    while (ans < 0) 
		ans += l;
	
    cout << ans << endl;
}