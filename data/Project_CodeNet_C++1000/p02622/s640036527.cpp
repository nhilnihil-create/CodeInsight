#include<bits/stdc++.h>
#define lint long long
#define st first
#define nd second
#define INF 0x3f3f3f3f

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s, t;
	cin>>s>>t;
	int ans = 0;
	for(int i=0;i<(int)s.size();i++)
		if(s[i] != t[i])ans++;
	cout<<ans<<"\n";
	return 0;	
}
