#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

const int MOD = 1000000007;
int main()
{
	int a, b;
	cin >> a >> b;
	int ara[b], s = 0;
	for(int i = 0 ; i< b; i++){
	 cin >> ara[i];s+= ara[i];
}
	if(s > a) cout << "-1" << endl;
	else cout << a - s << endl;
	
	
	return 0;
}
