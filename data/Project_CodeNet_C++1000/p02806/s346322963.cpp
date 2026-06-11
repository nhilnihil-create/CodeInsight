#include <bits/stdc++.h>
// #define che
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define fi first
#define se second
#define MK make_pair
#define PB push_back
using namespace std;

typedef long long LL;
typedef pair<int ,int> PII;
const int N=110;

string s[N];
int t[N];
int n;
int main(){
	#ifdef che
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	cin>>n;
	for (int i=0; i<n; ++i)cin>>s[i]>>t[i];
	string tar;cin>>tar;
	int res=0,flag=0;
	for (int i=0; i<n;++i){
		res += flag*t[i];
		if ( s[i]==tar) flag=1;
	}
	printf("%d\n", res);
	return 0;
}