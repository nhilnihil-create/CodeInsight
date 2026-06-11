#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	string S;
	cin >> S;
	if (S[S.size()-1] == 's') cout << S << "es" << endl;
	else cout << S << "s" << endl;
	return 0;
}