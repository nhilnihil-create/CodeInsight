#include<bits/stdc++.h>
using namespace std;

#define print(x) cout << #x << '=' << x << endl


int main()
{
	int n,f=1;
	string s;
	cin >> n >> s;

	if(n%2!=0)
		cout << "No" << endl;
	else{
		int mid=n/2;
		for( int i=0 ; i<mid ; i++ )
		{
			if(s[i]!=s[mid+i])
				f = 0;
		}
		if(f)
			cout << "Yes" << endl;
		else
		cout << "No" << endl;
	}

	return 0;
}
