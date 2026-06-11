#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
#define re return
#define all(a) a.begin(),a.end()
#define int long long
using namespace std;
int n,a,b;
string s;
int early[200005],late[200005];
signed main()
{
	cin>>n>>a>>b>>s;
	int y=0;
	for (int i=0;i<a;i++){
		for (int j=y;;j++){
			if (s[j]=='o'){
				early[i]=j;
				break;
			}
		}
		y=early[i]+b+1;
	}
	y=n-1;
	for (int i=a-1;i>=0;i--){
		for (int j=y;;j--){
			if (s[j]=='o'){
				late[i]=j;
				break;
			}
		}
		y=late[i]-b-1;
	}
	for (int i=0;i<a;i++){
		if (early[i]==late[i]){
			cout<<late[i]+1<<endl;
		}
	}
	re 0;
}