#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;	cin >> n;
  vector<int> A(n,0);
  for(int i=1;i<n;i++){
    int x;	cin >> x;	x--;
    A.at(x)++;
  }
  
  for(int i:A){
    cout << i << endl;
  }
}