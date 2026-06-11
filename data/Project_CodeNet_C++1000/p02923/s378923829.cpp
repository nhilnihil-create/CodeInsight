#include <bits/stdc++.h>
using namespace std;

int main(){
  int n ;
  cin >> n;
  int saidai = 0;
  int count = 0;
  vector<long long int> h(120000,9999999999) ;
  
  for(int i=0;i<n;i++){
    cin >> h[i];
  }
  for(int i=0;i<n;i++){
    if(h[i]>=h[i+1]){
      count++;
    }
    else {
      saidai = max(saidai,count);
      count = 0;
    }
  }
  
  cout << saidai << endl;
}
  

