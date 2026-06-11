#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,X=0;
  cin >> n;
  vector<int>vec(n);
  for(int i=0; i<n; i++){
    cin >> vec[i];
  }
  for(int i=1; i<n-1; i++){
   if(vec[i-1] < vec[i] && vec[i] < vec[i+1]){
     X++;
   }
    else if(vec[i-1] > vec[i] && vec[i] > vec[i+1]) {
      X++;
  }
  }
  cout << X << endl;
}