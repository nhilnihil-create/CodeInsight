#include<iostream>
#include<cmath>
using namespace std;

void insertionSort(long int A[], long int n, int g, int& count){
  int j,v;
  for(int i=g; i<n; i++){
    j=i-g;
    v = A[i];
    while(1){
      if(A[j] <= v){
        for(int k=i; k>=j+g; k-=g){
          //count++;
          A[k] = A[k-g];
        }
        A[j+g] = v;
        break;
      }
      j -= g;
      count++;
      if(j<0){
        for(int k=i; k>=j+g+g; k-=g){
          A[k] = A[k-g];
        }
        A[j+g] = v;
        break;
      }
    }
  }
}

void shellSort(long int A[], long int n){
  int count =0;
  int n_copy;
  int m = 0;
  int G[100];
  n_copy = n;
  G[0] = 1;
  for(int i=1; i<100; i++){
    G[i] = (G[i-1]*3) +1;
    m++;
    if(G[i] > n){
      break;
    }
  }
  cout <<m << endl;
  for(int i=0; i<m; i++){
    cout << G[m-1-i] << " ";
    insertionSort(A, n_copy, G[m-1-i], count);
  }
  cout << endl;
  cout << count << endl;
}

int main(){
  long int n;
  long int A[1000000];
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> A[i];
  }
  shellSort(A, n);
  for(int i=0; i<n; i++){
     cout << A[i] << endl;
  }
  return 0;
}
