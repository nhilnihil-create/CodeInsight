#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define puts(i) cout<<i<<endl
#define pi 3.14159265358979323846264338
#define pb push_back
#define mp make_pair
#define inf 10000
using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;

ll divisor=1000000007;

int main(){
	string s;
	cin>>s;
	rep(i,size(s)){
		if(s[i]=='?'){
			s[i]='D';
		}
	}
	int a=0;
	rep(i,size(s)){
		if(i==0&&s[0]=='D')a++;
		if(s[i]=='D'){
			a++;
			if(s[i-1]=='P')a++;
		}
	}
	puts(s);
}