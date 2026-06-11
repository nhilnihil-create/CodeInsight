#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
const int N=2e5+10;

int gi() {
	int x=0,o=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') o=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*o;
}

int n;
char s[N];

int main() {
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++) {
		if(s[i]=='?') s[i]='D';
		cout<<s[i];
	}
	return 0;
}
