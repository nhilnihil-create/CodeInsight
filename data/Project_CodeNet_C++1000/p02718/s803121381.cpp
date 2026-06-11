#include <bits/stdc++.h>
using namespace std;


int main() {
  int n,m;
  int flag = 0;

  cin >> n >> m;

  vector<int> a(n);

  int total = 0;

  for(int i=0; i<a.size(); i++){
    cin >> a.at(i);
    total += a.at(i);
  }

  sort(a.begin(),a.end(),greater<int>());


  double ninki = double(total/(4*m));

  //cout << ninki;

  for(int i = 0; i<m; i++){
    if(a.at(i)*4*m<total)
    flag++;
  }

  if(flag == 0)
  cout << "Yes";
  else
  cout << "No";


}