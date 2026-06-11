#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;	cin >> n >> m;
  vector<int>	A(n);
  double sum=0;
  for(int i=0;i<n;i++){
    cin >> A.at(i);
    sum+=A.at(i);
  }
  sort(A.rbegin(),A.rend());
  int c=0;
  for(int x:A){
    if(x<sum/4/m)	continue;
    c++;
  }
  if(c>=m)	cout << "Yes";
  else cout << "No";
}