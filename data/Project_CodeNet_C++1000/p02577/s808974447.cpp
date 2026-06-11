#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main(){
	string s;cin>>s;
	int cnt=0;
	for(char c:s){
		cnt+=c-'0';
	}
	puts(cnt%9==0?"Yes":"No");
}