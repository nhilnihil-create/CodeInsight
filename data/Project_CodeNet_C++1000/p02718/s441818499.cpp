#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, sum=0,count=0;
  cin >> n >> m;
  vector<int> a(n);
  for(int i=0; i<n ; i++){
    cin >> a.at(i);
  sum += a.at(i);
  }
  for(int k = 0;k<n ; k++){
    if(sum <= 4*m*a.at(k))
      count++;
  }
  
  if(count >= m)
    cout << "Yes" << endl;
  else cout << "No" << endl;
}