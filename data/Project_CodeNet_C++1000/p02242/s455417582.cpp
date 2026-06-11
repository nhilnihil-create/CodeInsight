#include<stdio.h>
#include<limits.h>
#define NIL -1
static const int MAX = 1005;
static const int INFTY = (1<<21);

main(){
  int n, i, j, v, c, u, k, minV;
  int M[MAX][MAX], A[MAX], key[MAX], p[MAX];
  /*your code*/

  scanf("%d", &n);
  for ( i = 0; i< n; i++ ){
    for ( j = 0; j < n; j++ ){
      M[i][j] = INFTY;
    }
  }

  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &u, &k);
    for ( j = 0; j < k; j++ ){
      scanf("%d %d", &v, &c);
      M[u][v] = c;
    }
  }

  /*your code*/
  for(i = 0; i < n; i++){
    key[i] = INT_MAX;
    p[i] = NIL;
    A[i] = NIL;
  }
  
  key[0]=0;
  
  while(1){
    
    u = NIL;
    
    minV = INT_MAX;
    
    for(i = 0;  i < n; i++){
      
      if(key[i] < minV && A[i] == NIL){
	
	u = i;
	
	minV = key[i];
	
      }
      
    }  
    if(u == NIL)break;
    
    A[u] = u; 
    
    for(v = 0; v < n; v++){
      if((M[u][v]+key[u]) < key[v] && A[v] == NIL){
	key[v] = (M[u][v]+key[u]);
	p[v] = u;
      }
    }
  }
  
  for ( i = 0; i < n; i++ ){
    printf("%d %d\n", i, (key[i]==INFTY?-1:key[i]));
  }

  return 0;

}