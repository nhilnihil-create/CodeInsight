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
	int n, m, item_popular, soma = 0, contador = 0;

	cin >> n >> m;
	vi v(n);
	for(int i=0; i < n; i++)
	{
		cin >> v[i];
		soma+= v[i];
	}

	item_popular = 4 * m;
	bool popular = false;
	for(int i=0; i<n; i++)
	{
		if(v[i]* 1LL * item_popular >= soma) contador++;
		if(contador == m)
		{ 
			popular = true;
			break;
		}
	}
	popular ? cout << "Yes\n" : cout << "No\n";
	return 0;
}