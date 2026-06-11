#include<bits/stdc++.h>
using namespace std;

int main(){

  int n, k;
  while( cin >> n >> k, n+k ) {
    int max_sum, sum = 0, data[100000];
    
    for(int i=0; i<k; i++) {
      cin >> data[i];
      sum += data[i];
    }
    max_sum =sum;

    for(int i=k; i<n; i++) {
      cin >> data[i];
      sum -= data[i-k];
      sum += data[i];
      max_sum = max(max_sum, sum);
    }

    cout << max_sum << endl;
  }
}