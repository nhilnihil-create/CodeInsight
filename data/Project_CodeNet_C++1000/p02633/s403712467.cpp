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

int gi() {
	int x=0,o=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') o=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*o;
}

int main() {
	int x;cin>>x;
	cout<<360/__gcd(360,x);
	return 0;
}
