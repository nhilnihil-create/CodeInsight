#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

char S[SIZE];
char T[SIZE];
vector<ll> V[26];


int main(){

	scanf("%s",S);

	int len_S = 0;
	for(ll i = 0; S[i]!= '\0'; i++,len_S++){

		V[S[i]-'a'].push_back(i);
	}
	scanf("%s",T);

	int len_T = 0;
	for(ll i = 0; T[i] != '\0'; i++,len_T++){

		if(V[T[i]-'a'].size() == 0){

			printf("-1\n");
			return 0;
		}
	}

	int loc = 0;
	ll ans = 0;

	while(loc < len_T){

		ll pos = -1;

		while(true){
			int next_ch = T[loc]-'a';

			if(V[next_ch][V[next_ch].size()-1] <= pos)break;

			int index = upper_bound(V[next_ch].begin(),V[next_ch].end(),pos)-V[next_ch].begin();

			pos = V[next_ch][index];

			loc++;
			if(pos == len_S-1)break;
			if(loc == len_T)break;
		}

		if(loc == len_T){

			ans += pos+1;
			break;

		}else{

			ans += len_S;
		}
	}

	printf("%lld\n",ans);

	return 0;
}
