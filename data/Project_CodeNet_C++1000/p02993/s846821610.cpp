#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<3;i++)
	if(s[i]==s[i+1]){
		cout<<"Bad\n";
		return 0;
	}
	cout<<"Good\n";
    return 0;
}

