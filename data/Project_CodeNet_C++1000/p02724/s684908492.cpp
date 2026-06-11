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
	
		int n;
		cin >> n;
		int ans = n / 500 * 1000;
		ans += n % 500 / 5 * 5;
		cout << ans << endl;
		return 0;

}




	

  

