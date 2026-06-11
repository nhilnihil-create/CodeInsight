#include <iostream>
using namespace std;

int insertionSort(int a[], int n, int g){
  int cnt = 0;
  for(int i=g; i < n; i++){
    int key = a[i];
    int j = i-g;
    while (j >= 0 && a[j] > key){
      a[j+g] = a[j];
      j -= g;
      cnt++;
    }
    a[j+g] = key;
  }
  return cnt;
}


void shellSort(int a[], int n){
  int count= 0;
  int m;
  int *G;
  G = new int[n];
  int h = 1;
  int j = 0;
  G[0] = 1;
  while(h < n){
    G[j++] = h;
    h = h * 3 + 1;
  }
  if(h == 1) m = 1;
  else m = j;
  cout << m << endl;
  cout << G[m-1];

  for(int i = m-2; i >= 0 ; i--){
    cout << " " << G[i];
  }
  cout << endl;
  for(int i = 0; i < m; i++){
    count += insertionSort(a, n, G[m-1-i]);
  }
  cout << count << endl;
  for(int i = 0; i < n; i++){
    cout << a[i] << endl;
  }
  return ;
}

int main(){
  int n;
  int a[1000000];
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  shellSort(a, n);
  return 0;
}