#include <iostream>

using namespace std;

int main(){

  int n,u,k,v,graph[106][106]={{}};

  cin >> n ;

  for(int i = 0; i < n; i++){
    cin >> u >> k ;
    for(int j = 0; j < k ; j++){
      cin >> v;
      graph[u][v] = 1;
    }
  }

  for(int i = 1; i<= u; i++){
    for(int j = 1; j<= u; j++){
      if(j != 1) cout <<  ' '<< graph[i][j] ;
      else cout << graph[i][j] ;
    }
    cout << endl;
  }


  return 0;
}