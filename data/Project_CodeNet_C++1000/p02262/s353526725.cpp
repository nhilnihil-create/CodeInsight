#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000

int a[MAX],N,cnt;

void insertionSort(int g){
  for(int i = g ; i < N ; i++){
    int v = a[i] , j = i-g;
    while(j >= 0 && a[j] > v){
      a[j+g] = a[j];
      j -= g;
      cnt++;
    }
    a[j+g] = v;
  }
}

void shellSort(){
  cnt = 0;
  int G[MAX],p = 0,m;

  for(m = 1 ; m*3+1 < N ; m = m*3+1);

  for(; m > 0 ; m /= 3){
    G[p++] = m;
  }

  if(p > 100){
    p = 100;
  }

  for(int i = 0 ; i < p ; i++){
    insertionSort(G[i]);
  }

  cout << p << endl;
  for(int i = 0 ; i < p ; i++){
    if(i != p-1){
      cout << G[i] << " ";
    }else{
      cout << G[i] << endl;
    }
  }

  cout << cnt << endl;
  for(int i = 0 ; i < N ; i++){
    cout << a[i] << endl;
  }

}

int main(){
  cin >> N;
  for(int i = 0 ; i < N ; i++){
    cin >> a[i];
  }
  shellSort();

  return 0;
}