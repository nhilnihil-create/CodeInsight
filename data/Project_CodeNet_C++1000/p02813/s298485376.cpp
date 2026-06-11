#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<int> a(n),p(n),q(n);
  for(int i = 0; i < n; i++){
    a.at(i) = i+1;
    cin >> p.at(i);
  }
  for(int i = 0; i < n; i++)
    cin >> q.at(i);
  if(p == q){
    cout << 0;
    return 0;
  }
  int x = 0,y = 0;
  int i = 1;
  do{
    if(a == p) x =i;
    else if(a == q) y = i;
    i++;
  }while(next_permutation(a.begin(),a.end()));
  cout << abs(x - y);
}