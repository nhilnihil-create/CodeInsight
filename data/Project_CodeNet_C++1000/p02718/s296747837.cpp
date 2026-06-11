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
	int N, M, sum = 0, cont = 0;
 
	cin >> N >> M;
	vector<int> v(N);
	for(int i=0; i < N; i++)
	{
		cin >> v[i];
		sum+= v[i];
	}
 
	bool popular = false;
	for(int i=0; i<N; i++)
	{
		if(v[i]*4*M >= sum) cont++;
		if(cont == M)
		{ 
			popular = true;
			break;
		}
	}
	popular ? cout << "Yes\n" : cout << "No\n";
	return 0;
}