#include<iostream>
using namespace std;

int cnt = 0;

int insertionsort(int *A, int size, int g){
  for(int i = g; i < size; i++){
    int v = A[i];
    int j = i - g;
    while(j >= 0 && A[j] > v){
      A[j + g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j + g] = v;
  }

  return 0;
}

int shellsort(int *A, int size, int *G, int gnum){
  cnt = 0;
  for(int i = gnum - 1; i >= 0; i--){
    insertionsort(A, size, G[i]);
  }
  return 0;
}

int main(){

  int size;

  cin >> size;

  int *A = new int[size];

  for(int i = 0; i < size; i++){
    cin >> A[i];
  }

  int G[100];

  G[0] = 1;

  int i = 1;

  while(i < 100 && G[i - 1] <= size / 2){
    G[i] = 3 * G[i - 1] + 1;
    i++;
  }
  if(i == 1) i++;
  int gnum = i - 1;

  shellsort(A, size, G, gnum);

  cout << gnum << endl;
  for(int i = gnum - 1; i > 0; i--){
    cout << G[i] <<" ";
  }
  cout << G[0] << endl;

  cout << cnt << endl;

  for(int i = 0; i < size; i++){
    cout << A[i] <<endl;
  }



  delete[] A;

  return 0;
}

