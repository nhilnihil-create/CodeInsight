#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


char S[4],T[4];

int main(){

	scanf("%s",S);
	scanf("%s",T);

	int ans = 0;

	for(int i = 0; i < 3; i++){
		if(S[i] == T[i]){

			ans++;
		}
	}

	printf("%d\n",ans);

	return 0;
}
