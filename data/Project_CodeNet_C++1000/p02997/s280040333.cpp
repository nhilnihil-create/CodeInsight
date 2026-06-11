#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



struct Edge{
	Edge(int arg_from,int arg_to){
		from = arg_from;
		to = arg_to;
	}
	int from,to;
};


int main(){

	int N,K;

	scanf("%d %d",&N,&K);

	if(K > ((N-1)*(N-2))/2){

		printf("-1\n");
		return 0;
	}

	ll num_2 = (N-1)*(N-2)/2;
	vector<Edge> V;

	for(int i = 2; i <= N; i++){

		V.push_back(Edge(1,i));
	}

	int base = 2;

	while(num_2 > K){

		if(num_2-(N-base) > K){
			for(int i = base+1; i <= N; i++){
				V.push_back(Edge(base,i));
			}
			num_2 -= (N-base);
			base++;
			continue;
		}else{

			for(int i = base+1; i <= N && num_2 > K; i++){
				V.push_back(Edge(base,i));
				num_2--;
			}
			break;
		}
	}

	printf("%lld\n",V.size());

	for(int i = 0; i < V.size(); i++){

		printf("%d %d\n",V[i].from,V[i].to);
	}

	return 0;
}
