#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 200005

char S[SIZE];
map<ll,ll> MAP;


int main(){

	scanf("%s",S);

	int len;
	for(len = 0; S[len] != '\0'; len++);

	ll num = 0,mult = 1;
	ll ans = 0;

	for(int i = len-1; i >= 0; i--){

		MAP[num]++;
		num += mult*(S[i]-'0');
		num %= 2019;

		ans += MAP[num];
		mult *= 10;
		mult %= 2019;
	}

	printf("%lld\n",ans);

	return 0;
}
