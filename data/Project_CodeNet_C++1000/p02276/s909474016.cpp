//#include<bits/stdc++.h>
#include<iostream>
#define MAX 100000
int partition(int,int);

using namespace std;
int S[MAX];
int n;

int main(){
  int i;
  int q;
  cin >> n;

  for(i = 0; i < n; i++){
    cin >> S[i];
  }
  q = partition(0,n-1);
  for(i = 0; i < n; i++){
    if(0 < i){
      cout << " ";
    }
    if(i == q){
      cout << "[";
    }
    cout << S[i];
    if(i == q){
      cout << "]";
    }
  }
  cout << endl;
  return 0;
}//end main func

int partition(int p,int r){
  int i,j,x;
  int tmp;
  x = S[r];
  i = p-1;
  for(j = p; j < r; j++){
    if(S[j] <= x){
      i++;
      tmp = S[i];
      S[i] = S[j];
      S[j] = tmp;
    }
  }
  tmp = S[i+1];
  S[i+1] = S[r];
  S[r] = tmp;
  return i+1;
}// end partition func