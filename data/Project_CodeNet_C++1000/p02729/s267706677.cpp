#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<math.h>
#include<stack>
#include<set>
#include<map>
#define INF 2e9
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;

vector<int>a[200000];

int main()
{
	int N, M;
	cin >> N >> M;
	cout << N * (N - 1) / 2 + M * (M - 1) / 2 << endl;
	return 0;
}
