/*A - Headphones */

#include <bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int ans = 0;
	int friends, conex;

	cin >> conex >> friends;

	if(friends != 1)
	{

		while(friends > 0){

			friends -= conex;
			
			if(friends > 0)
				friends++;

			ans++;
		}
	}



	cout << ans;


	return 0;
}