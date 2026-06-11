#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int N;
vector<int> V;

int main(){

	scanf("%d",&N);

	int tmp;
	for(int i = 0; i < N; i++){

		scanf("%d",&tmp);
		V.push_back(tmp);
	}

	sort(V.begin(),V.end());

	if(V[N/2] == V[N/2-1]){

		printf("0\n");
		return 0;

	}else{

		printf("%d\n",V[N/2]-V[N/2-1]);
	}

	return 0;
}
