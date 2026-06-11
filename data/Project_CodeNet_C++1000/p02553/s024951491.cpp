#include<bits/stdc++.h>
#define fs first
#define se second
#define pb push_back
#define cppio ios::sync_with_stdio(false);cin.tie(0)
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;

const int maxn=1e5+5;
const ll inf=0x3f3f3f3f;
const ll mod=1e9+7;

int main(){
	ll a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	printf("%lld",max(a*c,max(a*d,max(b*c,b*d))));
	return 0;
}
