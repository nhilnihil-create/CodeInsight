#include<iostream>

using namespace std;
const int MAX = 11;
const int INF = (1<<20);
int D[MAX][MAX];
int n, pos;

void init(){
  for(int i = 0; i < MAX; i++)
    for(int j = 0; j < MAX; j++)
      D[i][j] = INF;

  pos = 0;
}

void solve(){

  for(int i = 0; i < MAX; i++)
    D[i][i] = 0;

  for(int k = 0; k < MAX; k++)
    for(int i = 0; i < MAX; i++)
      for(int j = 0; j < MAX; j++)
	D[i][j] = min(D[i][j],D[i][k]+D[k][j]);

  int city = -1, T = INF;

  for(int i = 0; i <= pos; i++){
    int tmp = 0;
    for(int j = 0; j <= pos; j++)
      tmp += D[i][j];
    
    if(T > tmp){
      city = i;
      T = tmp;
    }
  }
  cout << city << " " << T << endl;
}
int main(){
 
  while(cin >> n && n){
    init();
    for(int i = 0; i < n; i++){
      int f,t,c;
      cin >> f >> t >> c;
      pos = max(pos,max(f,t));
      D[f][t] = D[t][f] = c;
    }
    solve();
  }
  return 0;
}