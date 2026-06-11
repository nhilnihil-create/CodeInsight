#include <iostream>
#include <math.h>

using namespace std;

//= AOJ GRL_1_A


const int V_constraint=1000,E_constraint=2000, D_constraint=10000;
int V, E, R,S[E_constraint+10], T[E_constraint+10], D[E_constraint+10],C[V_constraint+10];
const int inf=V_constraint*D_constraint+100;
// int parent[100000];

int main() {
	
	
	//= prompt user for input
	cin >> V >> E >> R;
if (E>E_constraint)
	cout<< "E violates constraints";
for (int i=0; i<E; ++i){
	cin >> S[i] >> T[i] >> D[i];
	if (D[i] >D_constraint || D[i]<D_constraint*-1)
	cout<< "D violates constraints";
}
// set distance from source to source as zero, other as infinite
for (int i=0;i<V;i++) C[i]=inf;
C[R]=0;


//= bellman-ford algo
for (int v=0;v<V-1;v++)
{
	bool update = false;

	for (int i=0;i<E;++i){
		if(C[S[i]]+D[i]<C[T[i]] && C[S[i]]<inf ){
		C[T[i]]=C[S[i]]+D[i];
		update = true; 
		
	
		}
}
if (!update) break; 
	}


//= for negative cycle
int neg_cyc =0;
for (int i=0;i<E;i++){
	if (C[S[i]] != inf && D[i]!= inf)
		if(C[S[i]] + D[i] < C[T[i]])
			neg_cyc=1;
}

if (neg_cyc==1)
	cout <<"NEGATIVE CYCLE"<<endl;
else {
for (int i=0; i<V; i++)
	if (C[i]!=inf)
	cout << C[i] <<endl;
	else
	cout <<"INF"<<endl;
}	

	return 0;
}