#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
int cnt[26];
signed main(){
	ios_base::sync_with_stdio(0);
	string s;
	cin>>s;
	for(int i=0;i<sz(s);i++) cnt[s[i]-'A']++;
	int tmp=0;
	for(int i=0;i<26;i++) if(cnt[i]==2) tmp++;
	cout<<(tmp==2?"Yes":"No");
	re 0;
}