#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
int main(){
  int N,i,j,c,l,r;scanf("%d",&N);
  int A[N][N-1],itr[N] = {};
  c = N*(N-1)/2;
  for(i=0;i<N;i++){
    for(j=0;j<N-1;j++){
      scanf("%d",&A[i][j]);A[i][j]--;
    }
  }
  queue<pair<int,int>> q;int game;
  for(i=0;i<N-1;i++){
    if(i < A[i][itr[i]] && A[A[i][itr[i]]][itr[A[i][itr[i]]]] == i) q.push(make_pair(i,A[i][itr[i]]));
  }
  for(i=0;c;i++){
    game = q.size();
    if(game == 0){
      printf("-1\n");return 0;
    }
    for(j=0;j<game;j++){
      l = q.front().first;r = q.front().second;q.pop();
      c--;
      itr[l]++;itr[r]++;
      if(itr[l] < N-1 && itr[A[l][itr[l]]] < N-1 && A[A[l][itr[l]]][itr[A[l][itr[l]]]] == l) q.push(make_pair(l,A[l][itr[l]]));
      if(itr[r] < N-1 && itr[A[r][itr[r]]] < N-1 && A[A[r][itr[r]]][itr[A[r][itr[r]]]] == r) q.push(make_pair(r,A[r][itr[r]]));
    }
  }
  printf("%d\n",i);
}