#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()

int main(){
	int n; string s; cin>>n>>s;
	string s2=s;
	sort(all(s2));
	int cnt=0;
	rep(i,n){
		if(s2[i]!=s[i]) cnt++;
	}
	cout<<cnt/2<<endl;
}