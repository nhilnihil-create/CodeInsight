/*D - ... (Triple Dots)*/

#include <bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int k;
	string cad;
	
	cin >> k >> cad;

	int tam = cad.size();

	if(tam > k){

		for (int i = 0; i < k; ++i)
			cout << cad[i];
		
		cout << "...";
	}
	else
		cout << cad;

	return 0;
}