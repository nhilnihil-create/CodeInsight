#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  
  vector<int> p(n);
  for(int i=0; i<n; i++){
    cin >> p[i];
  }
  
  int j=0;
  int num=0;
  while(j<n-2){
    if(p[j] >= p[j+1] && p[j+2] < p[j+1]){
      num++;
    }
    else if(p[j] > p[j+1] && p[j+2] <= p[j+1]){
      num++;
    }
    else if(p[j] <= p[j+1] && p[j+2] > p[j+1]){
      num++;
    }
    else if(p[j] < p[j+1] && p[j+2] >= p[j+1]){
      num++;
    }
    j++;
  }
  
  cout << num << endl;
}
