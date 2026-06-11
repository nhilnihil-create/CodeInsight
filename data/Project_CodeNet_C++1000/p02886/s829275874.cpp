#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n, total=0;
  cin >> n;
  int line[n];
  for(int i=0;i<n;i++){
    cin >> line[i];
  }
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      total += line[i]*line[j];
    }
  }
  cout << total << endl;
}