#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

#define endl "\n"

int main()
{
	faster;
	
	int n;
	cin >> n;
	bool contains = false;
	while(n > 0){
		if(n%10 == 7) contains = true;
		n /= 10;
	}

	cout << (contains ? "Yes" : "No") << endl;
	
	return 0;
}