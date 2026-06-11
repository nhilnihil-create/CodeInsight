#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF 1LL<<60
#define rep(i,n) for(ll i=0;i<n;i++)
#define Graph vector<vector<ll>>
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

ll n;
void dfs(string s,char s2){
	if(s.size()==n){
		cout<<s<<endl;
		return;
	}

	for(char c='a';c<=s2;c++){//c==s2なら、存在する文字を調べ尽くしたので、次の文字を調べる(s2=a,b,cまで調べたら、次はs2+1=dも調べる)
		dfs(s+c,(c==s2)?(char)(s2+1):s2);
	}

	return;
}

int main(){
	cin>>n;
	dfs("",'a');
	return 0;
}