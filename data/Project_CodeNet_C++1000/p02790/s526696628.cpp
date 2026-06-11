#include <iostream>
#include<iomanip>
#include <string>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<math.h>
#include<stack>
#include<set>
#include<map>
#define INF long long int(1e18+1)
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;

int main() 
{
	int n, m;
	cin >> n >> m;
	if (n <= m)rep(i, 0, m)cout << n;
	else rep(i, 0, n)cout << m;
}


