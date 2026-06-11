#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000

long long cnt;
int l;
int A[MAX];
int n;
vector <int> G;

void insertionSort(int[], int, int);
void shellSort(int[], int);

int main(){
  int i;
  cin >> n;
  for(i = 0; i < n; i++){
    cin >> A[i];
    //scanf("%d",&A[i]);
  }
  cnt = 0;
  shellSort(A,n);
  cout << G.size() << endl;
  for(i = G.size() - 1 ; i >= 0; i--){
    cout << G[i];
    if(0 < i){
      cout << " ";
    }
  }
  cout << endl;
  cout << cnt << endl;
  for(i = 0; i < n; i++){
    cout << A[i] << endl;
  }
  return 0;
}

void insertionSort(int A[], int n, int g){
  int i,j,v;
  for(i = g; i < n; i++){
    v = A[i];
    j = i - g;
    while( j >= 0 && A[j] > v){
      A[j + g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j + g] = v;
  }
}

void shellSort(int A[], int n){
  int i,h;
  for(h = 1;;){
    if(n < h){
      break;
    }
    G.push_back(h);
    h = 3*h + 1;
  }
  for(i = G.size() - 1; i >= 0; i--){
    insertionSort(A, n, G[i]);
  }
}