//設定言語check
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <limits.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
using namespace std;

int root(int a, int par[]){
  if(par[a] == a) return a ;
  return par[a] = root(par[a],par) ;
}

int main(){
  int N, M, ans = 0, roadA, roadB, rA, rB ;
  cin >> N >> M ;
  ans = N-1 ;
  int par[N+1] = {} ;
  for(int i=1;i<=N;i++) par[i] = i ;
  for(int i=0;i<M;i++){
    cin >> roadA >> roadB ;
    rA = root(roadA, par) ;
    rB = root(roadB, par) ;
    if(rA == rB) continue ;
    else{
      par[rA] = rB ;
      ans-- ;
    }
  }  
  cout << ans << endl ;
  return 0 ;
}