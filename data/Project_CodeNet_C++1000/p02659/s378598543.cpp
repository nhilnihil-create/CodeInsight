#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

ll a;
string b;

int main(void){
	cin >> a >> b;
	ll bb=0;
	bb=(b[0]-'0')*100+(b[2]-'0')*10+(b[3]-'0');
	ll c=a*bb;
	printf("%lld\n",c/100LL);
	return 0;
}
