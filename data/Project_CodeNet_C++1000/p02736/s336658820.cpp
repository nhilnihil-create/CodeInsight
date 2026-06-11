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
const int N=1e6+10;

int gi() {
	int x=0,o=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') o=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*o;
}

int n,a[N];
char s[N];

bool C(int n,int m) {
	return (n&m)==m;
}

int work(bool f) {
	bool tmp=0;
	for(int i=1;i<=n;i++)
		if(a[i]==1) tmp^=C(n-1,i-1);
	if(tmp) return 1+int(f);
	bool fl=0;
	for(int i=1;i<=n;i++)
		if(a[i]==1) fl=1;
	if(fl||f) return 0;
	for(int i=1;i<=n;i++) a[i]/=2;
	return work(1);
}

int main() {
	cin>>n;scanf("%s",s+1);
	for(int i=1;i<=n;i++) a[i]=s[i]-'0'-1;
	cout<<work(0);
	return 0;
}
