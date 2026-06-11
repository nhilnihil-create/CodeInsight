#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int main(){
  int n;
  cin >> n;
  vector<int> p(n),q(n),a(n);
  for(int i=0;i<n;i++){
    cin >> p.at(i);
  }
  for(int i=0;i<n;i++){
    cin >> q.at(i);
  }
  for(int i=0;i<n;i++){
    a.at(i) = i+1;
  }
  int count,aa,b;
  do{
    bool flaga = true;
    bool flagb = true;
    for(int i=0;i<n;i++){
      if(a.at(i) != p.at(i)){
        flaga = false;
      }
    }
    for(int i=0;i<n;i++){
      if(a.at(i) != q.at(i)){
        flagb = false;
      }
    }
    if(flaga) aa = count;
    if(flagb) b = count;
    count++;
  }while(next_permutation(a.begin(),a.end()));
  cout << abs(b-aa) << endl;
}