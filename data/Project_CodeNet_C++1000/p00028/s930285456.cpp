//Mode Value
#include<bits/stdc++.h>
using namespace std;

pair<int, int> d[101];

bool cmp(pair<int, int> l, pair<int, int> r){
  if(l.first>r.first) return true;
  if(l.first==r.first) return l.second < r.second;
  return false;
}

int main(){
  int n;
  for(int i=0; i<101; i++){
    d[i].first = 0;
    d[i].second = i;
  }
  while(cin >> n){
    d[n].first++;
  }
  sort(d, d+101, cmp);
  for(int i=0; i<101; i++){
    if(d[0].first > d[i].first)break;
    cout << d[i].second << endl;
  }
  return 0;
}