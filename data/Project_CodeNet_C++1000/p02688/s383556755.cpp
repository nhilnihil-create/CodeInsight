#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int n,k;
  cin >> n >> k;
  vector<int> v(n,0);
  int d,a;
  for(int i = 0; i<k; i++){
    cin >> d;
    for(int j=0; j<d; j++){
      cin >> a;
      v.at(a-1) = 1;
    }
  }
  int count = 0;
  for(int x: v){
    if(x == 0){
      count++;
    }
  }
  cout << count << endl;
}