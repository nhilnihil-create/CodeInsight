#include<bits/stdc++.h>
#define endl "\n"
#define int long  long 

using namespace std ; 
	 
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;

	string s1 , s2  ; 
	cin >> s1 >> s2 ; 
	int cnt= 0 ; 
	for(int i = 0; i < s1.size() ; ++i)
	{
		if(s1[i] != s2[i])
			cnt++ ; 
	}
	cout <<  cnt ; 
}       



