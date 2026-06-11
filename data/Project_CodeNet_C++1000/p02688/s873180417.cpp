#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k;	cin >> n >> k;
  vector<int>	data(n);
  for(int i=0;i<k;i++){
    int d;	cin >> d;
    for(int j=0;j<d;j++){
      int a;	cin >> a;	a--;
      data.at(a)++;
    }
  }
  cout << count(data.begin(),data.end(),0);
}