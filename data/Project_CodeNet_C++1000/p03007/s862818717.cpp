#include<iostream>
#include<algorithm>
using namespace std;

int N;
int A[100000];

void all_minus(){
  int M = A[N - 1];
  for(int i = 0; i < N - 1; i++){
    M -= A[i];
  }
  cout << M << endl;
  int left = A[N - 1];
  for(int i = 0; i < N - 1; i++){
    cout << left << ' ' << A[i] << endl;
    left -= A[i];
  }
}

void all_plus(){
  int M = -A[0];
  for(int i = 1; i < N; i++){
    M += A[i];
  }
  cout << M << endl;
  int left = A[0];
  for(int i = 1; i < N - 1; i++){
    cout << left << ' ' << A[i] << endl;
    left -= A[i];
  }
  cout << A[N - 1] << ' ' << left << endl;
};

void mixed(){
  int M = 0;
  for(int i = 0; i < N; i++){
    M += abs(A[i]);
  }
  cout << M << endl;

  int left1 = A[N - 1];
  for(int i = 1; i < N - 1 && A[i] <= 0; i++){
    cout << left1 << ' ' << A[i] << endl;
    left1 -= A[i];
  }

  int left2 = A[0];
  for(int i = N - 2; i > 0 && A[i] > 0; i--){
    cout << left2 << ' ' << A[i] << endl;
    left2 -= A[i];
  }

  cout << left1 << ' ' << left2 << endl;
}

int main(){
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  sort(A, A + N);

  if(A[N - 1] <= 0){
    all_minus();
  }else if(A[0] >= 0){
    all_plus();
  }else{
    mixed();
  }
}

