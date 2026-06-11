#include<bits/stdc++.h>
#define lint long long
#define st first
#define nd second
#define INF 0x3f3f3f3f

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	vector<lint> v(n);
	lint s=0;
	for(lint &x:v){cin>>x;s+=x;}
	
	lint s2=0;
	lint ans = s;
	for(int i=0;i<n;i++){
		s2 += v[i];
		s -= v[i];
		cerr<<s-s2<<"\n";
		ans = min(ans, abs(s-s2));
	
	}	
	cout<<ans<<"\n";

	return 0;	
}
