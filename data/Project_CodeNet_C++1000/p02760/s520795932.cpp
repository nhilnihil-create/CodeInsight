#include <bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
 
using namespace std;
using vi=vector<int>;
using pii=pair<int, int>;
using ull=unsigned long long;
using ll=long long;
int m[3][3];
bool ac[3][3];

bool verify()
{
	// row
	for (int i = 0; i < 3; i++)
		if (ac[i][0] == 1 && ac[i][1] == 1 && ac[i][2] == 1)
			return true;

	//column
	for (int i = 0; i < 3; i++)
		if (ac[0][i] == 1 && ac[1][i] == 1 && ac[2][i] == 1)
			return true;

	//diagonal
	if (ac[0][0] == 1 && ac[1][1] == 1 && ac[2][2] == 1)
		return true;

	if (ac[0][2] == 1 && ac[1][1] == 1 && ac[2][0] == 1)
		return true;

	return false;
}

void search(int n){
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (m[i][j] == n)
				ac[i][j] = 1;
	
}
 
int main()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> m[i][j];

	int n; cin >> n;
	for (int i = 0; i < n; i++){
		int num;
		cin >> num;

		search(num);

	}

	if (verify())
		cout << "Yes\n";
	else
		cout << "No\n";

}
