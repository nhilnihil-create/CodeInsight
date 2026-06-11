#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; cin>>n;
	string s;
	for(int i=1; i<=n; i++) s+=to_string(i);
	string p,q;
	rep(i,n){
		int a; cin>>a;
		p+=to_string(a);
	}
	rep(i,n){
		int a; cin>>a;
		q+=to_string(a);
	}
	int a,b,cnt=0;
	do{
		cnt++;
		if(p==s) a=cnt;
		if(q==s) b=cnt;
	}while(next_permutation(s.begin(),s.end()));
	cout<<abs(a-b)<<endl;
}