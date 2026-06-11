#include <bits/stdc++.h>
using namespace std;

int main()
{
	   int a, b;
	   
	   cin >> a >> b;
	   
	   int empty = 1, ans = 0;
	   
	   while(empty < b){
				    ans++;
				    empty--;
				    empty += a;
				}
				
				cout << ans << "\n";
	   
    return 0;
}
