#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;


int main()
{
	int N, count=0;
	string S;
	cin >> N >> S;
	
	rep(i, N-2) {
		if (S.at(i)=='A'&& S.at(i+1) == 'B' && S.at(i+2) == 'C')
		{
			count++;
		}
	}
	cout << count << endl;
}