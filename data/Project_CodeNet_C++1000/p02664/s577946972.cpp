#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using Graph = vector< vector<int> >;

int main(){
	string T;
	cin >> T;
	for (int i = 0; i < T.size(); i++)
	{
		if(T[i]=='?') T[i] = 'D';
	}
	cout << T << endl;
}