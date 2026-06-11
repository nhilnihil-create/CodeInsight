#include <iostream>
#include <algorithm>

const int inf = 99999;

using namespace std;

int main()
{
	int a[11][11], n, s, t, u, v;
	
	while(1){
		cin >> n;
		if(n == 0){
			break;
		}
		fill(&a[0][0], &a[10][10], inf);
		for(int i = 0; i < 11; i++){
			a[i][i] = 0;
		}
		v = 0;
		for(int i = 0; i < n; i++){
			cin >> s >> t >> u;
			a[s][t] = a[t][s] = u;
			if(v < s){
				v = s;
			}
			if(v < t){
				v = t;
			}
		}
		
		for(int k = 0; k <= v; k++){
			for(int i = 0; i <= v; i++){
				for(int j = 0; j <= v; j++){
					a[i][j] = (a[i][j] > a[i][k]+a[k][j])? a[i][k]+a[k][j] : a[i][j];
				}
			}
		}
		
		t = inf;
		for(int i = 0; i <= v; i++){
			s = 0;
			for(int j = 0; j <= v; j++){
				s += a[i][j];
			}
			if(t > s){
				t = s;
				u = i;
			}
		}
		cout << u << " " << t << endl;
	}
	
	return 0;
}