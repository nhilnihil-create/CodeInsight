#include<bits/stdc++.h>
#define ull unsigned long long
#define pi acos(-1)
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f;
const ll maxn = 1e7+5;
const ll mod = 1e9+7;

int main(){
	int n,cnt=0;
	string s;
	cin>>n>>s;
	for(int i=0;i<n-2;i++){
		if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C') cnt++;
	} 
	cout<<cnt<<'\n';
	return 0;
}
