/**   
 *   Author:    @glaucoacassioc
 *   Created on 11.09.2020, 16:56:16
**/
#include <bits/stdc++.h>

using namespace std;
  
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, item_popular, sum = 0, cont = 0;
 
	cin >> n >> m;
	vector<int> v(n);
	for(int i=0; i < n; i++)
	{
		cin >> v[i];
		sum+= v[i];
	}
 
	item_popular = 4 * m;
	bool popular = false;
	for(int i=0; i<n; i++)
	{
		//Quer saber se um item eh popular, so eh popular se for menor que 1/4*m do total de votos.
		//Soma os votos pra saber qual eh o total de votos  v[i] * 1 * 4 * m;
		if(v[i] * 1LL * item_popular >= sum) cont++;
		if(cont == m)
		{ 
			popular = true;
			break;
		}
	}
	popular ? cout << "Yes\n" : cout << "No\n";
	return 0;
}