#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> coletado;
multiset<int> valores; 
int N, M, impossivel;

int main(){

	scanf("%d", &M);
	N = (1 << M);
	for(int i = 1;i<=N;i++){
		int x;
		scanf("%d", &x);
		valores.insert(x);
	}

	coletado.push(*prev(valores.end()));
	valores.erase(prev(valores.end()));


	while(!valores.empty()){

		queue<int> fila;

		while(!coletado.empty()){
			int v = coletado.top();
			coletado.pop();
			multiset<int>::iterator it = valores.lower_bound(v);
			if(it == valores.begin()){
				impossivel = 1;
				break;
			}
			it = prev(it);
			fila.push(*it);
			valores.erase(it);
			fila.push(v);
		}

		if(impossivel) break;

		while(!fila.empty()){
			int v = fila.front();
			fila.pop();
			coletado.push(v);
		}

	}

	if(impossivel) printf("No\n");
	else printf("Yes\n");

	return 0;

}