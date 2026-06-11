#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	//freopen("input.in","r",stdin);
	//freopen("output.in","w",stdout);
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i,j,k;
    string s;
    cin>>s;
    int ans(0);
    for(auto ch:s)ans+=ch-'0'; 
    if(ans%9)cout<<"No\n";
	else cout<<"Yes\n";
	
	
	







	return 0;
}