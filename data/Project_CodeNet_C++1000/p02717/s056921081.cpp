/**   
 *   Author:    @glaucoacassioc
 *   Created on 11.09.2020, 15:32:16
**/
#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
vector<vii> AdjList;

vi pai, color, dist, ts;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;

	cin >> a >> b >> c;
	swap(a,b);
	swap(a,c);
	cout << a <<" "<< b <<" "<< c <<endl;

	return 0;
}