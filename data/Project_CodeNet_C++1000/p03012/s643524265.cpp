#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> w(n);
  int i,j;
  for(i=0;i<n;i++) cin >> w[i];
  int min = 10000;
  for(i=0;i<n-1;i++){
    int s1=0;
    int s2=0;
    for(j=0;j<=i;j++) s1 += w[j];
    for(j=i+1;j<n;j++) s2 += w[j];
    if(min>abs(s1-s2)) min = abs(s1-s2);
  }
  cout << min << "\n";
  return 0;
}