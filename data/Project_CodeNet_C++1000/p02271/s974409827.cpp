#include<iostream>
#include<string>
using namespace std;

int n;

//int *A;

int A[20];

bool solve(int i, int m){
  if(m == 0){
    return 1;
  }
  else if(i >= n){
    return 0;
  }

  return solve(i + 1, m) || solve(i + 1, m - A[i]);
}

int main(){

  int q, m;

  cin >> n;

  //A = new int[n];

  //string *ans = new string[q];

  int ans[200];


  for(int i = 0; i < n; i++){
    cin >> A[i];
  }

  cin >> q;

  for(int i = 0; i < q; i++){
    cin >> m;
    if(solve(0, m) == 1){
      ans[i] = 1;
    }
    else{
      ans[i] = 0;
    }
  }

  for(int i = 0; i < q; i++){
    if(ans[i]){
      cout << "yes" << endl;
    }
    else{
      cout << "no" << endl;
    }
  }


  return 0;
}

