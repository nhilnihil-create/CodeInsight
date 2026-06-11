#include<bits/stdc++.h>
#define lint long long
#define st first
#define nd second
#define INF 0x3f3f3f3f

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s;
	cin>>s;
	if(s[2] == s[3] && s[4] == s[5])
		cout<<"Yes\n";
	else cout<<"No\n";

	return 0;	
}
