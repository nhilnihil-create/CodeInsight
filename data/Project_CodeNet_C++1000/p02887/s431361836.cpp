#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string s;
	cin>>n>>s;
	int ans=1;
	for(int i=1; i<n; i++){
		if(s[i]==s[i-1]){
			continue;
		}
		else{
			ans++;
		}
	}
	cout<<ans;
	return 0;

}