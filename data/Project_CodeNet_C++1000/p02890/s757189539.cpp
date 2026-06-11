#include <bits/stdc++.h>

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

//Pasos para el desarrollo
//1) Nos damos cuenta de que al crecer el valor de K, el número de operaciones es decreciente
//2) Vamos a resolver el problema al revés: para un número de operaciones fijos, buscamos el mayor K
//3) Luego para un valor de k, buscamos cuál es el máx. número de op. que tuve el valor de k asociado mayor

using namespace std;

int rep[3*(int)1e5 + 1];
int opToMaxK[3*(int)1e5 + 1];
int rem[3*(int)1e5 + 1];

int main(){
	optimizar_io;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		int v;
		cin >> v;
		rep[v-1]++;
	}
	sort(rep, rep + N, greater<int>());
	for (int i = N - 1; i >= 0; i--){
		rem[i] = rem[i+1] + rep[i];
	}
	for (int op = 1; op <= N; op++){
		//Buscamos la cantidad de cartas con op o mas apariciones
		int geq = (upper_bound(rep, rep + N, op, greater<int>()) - rep);
		int max_k = geq + rem[geq] / op;
		opToMaxK[op] = max_k;
	}
	for (int k = 1; k <= N; k++){
		//Tenemos que busca la mayor operación que tuve valor mayor o igual que k
		int geq = (upper_bound(opToMaxK + 1, opToMaxK + N + 1, k, greater<int>()) - (opToMaxK + 1));
		cout << geq << endl;
	}
	return 0;
}
