#include<iostream>
#include<vector>

using namespace std;

int d[10][10];

int main()
{
	for(;;){
		int n, t_cont = 0, best_t = -1;
		int from, to, cost, cont = 0;
		int Min = 1000000000;
		bool isUsed[11] = {0};
		
		
		//INFツづ渉可甘コツ可サ
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 10; j++){
				d[i][j] = 100000;
				if(i == j){
					d[i][j] = d[j][i] = 0;
				}
			}
		}
		
		cin >> n;
		if(n == 0){
			break;
		}
		
		for(int i = 0; i < n; i++){
			cin >> from >> to >> cost;
			d[from][to] = d[to][from] = cost;
			isUsed[from] = 1;
			isUsed[to] = 1;
		}
		
		for(int i = 0; i < 11; i++){
			if(isUsed[i] == 1){
				t_cont++;
			}
		}
		
	//	cout << t_cont << endl;
		
		//ツδ渉ーツシツδδδ仰づ猟ャツつキ
		
		for(int k = 0; k < t_cont; k++){
			for(int i = 0; i < t_cont; i++){
				for(int j = 0; j < t_cont; j++){
					d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
				}
			}
		}
		/*
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 10; j++){
				printf("%d   ",d[i][j]);
			}
			cout << endl;
		}
		*/
		//ツ全ツ閉板個ゥツづゥ
		for(int i = 0; i < t_cont; i++){
			for(int j = 0; j < t_cont; j++){
				cont += d[i][j];
			}
			if(cont < Min){
				Min = cont;
				best_t = i;
			}
			cont = 0;
		}
		
		cout << best_t << " " << Min << endl;
	}
}