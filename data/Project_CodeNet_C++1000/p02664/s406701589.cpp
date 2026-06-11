#include <bits/stdc++.h>
using namespace std;
int main()
{
	string t;
	cin >> t;
	int n = t.size();
	for(int i=0;i< n;i++){
		if(t[i]=='?')
			t[i]='D';
	}
	cout << t << endl;
    return 0;
    
}