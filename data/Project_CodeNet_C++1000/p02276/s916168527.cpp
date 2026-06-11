#include<iostream>
#include<string>
#include<math.h>
#include<iomanip>
using namespace std;

int partition(int *A, int p, int r){
  int x = A[r];
  int i = p - 1;
  for(int j = p; j < r; j++){
    if(x >= A[j]){
      i++;
      int temp = A[j];
      A[j] = A[i];
      A[i] = temp;
    }
  }
  A[r] = A[++i];
  A[i] = x;
  return i;
}


int main(){

  int n;

  cin >> n;
  int *A = new int[n];

  for(int i = 0; i < n; i++){
    cin >> A[i];
  }

  int index = partition(A, 0, n - 1);


  for(int i = 0; i < n; i++){
    if(i == n - 1){
      if(i == index){
        cout << '[' << A[i] << ']' << endl;
      }
      else{cout << A[i] << endl;}
    }
    else{
      if(index == i){
        cout << '[' << A[i] << ']' << ' ';
      }
      else{cout << A[i] << ' ';}
    }
  }


  delete[] A;
  return 0;
}

