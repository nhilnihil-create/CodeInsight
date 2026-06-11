#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;

int main(){
	string s;cin>>s;
	int ans=0;
	for(int i=0,j=s.length()-1;i<j;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
}