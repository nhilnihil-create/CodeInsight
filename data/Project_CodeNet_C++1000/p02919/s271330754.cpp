#include<bits/stdc++.h>

using namespace std;

int main(){
  int N;
  cin >> N;
  priority_queue<pair<int, int>> P;
  for(int i = 0; i < N; i++){
    int in;
    cin >> in;
    P.push(make_pair(in, i));
  }
  
  multiset<int> place;
  place.insert(-1); place.insert(-1);
  place.insert(N); place.insert(N);
  
  long long second_sum = 0;
  while(!P.empty()){
    auto p = P.top();
    P.pop();
    
    int leftleft, left, right, rightright;
    auto itr = place.lower_bound(p.second);
    right = *itr;
    rightright = *(++itr);
    --itr;
    left = *(--itr);
    leftleft = *(--itr);
    
    second_sum += (long long)(left - leftleft) * (right - p.second) * p.first;
    second_sum += (long long)(rightright - right) * (p.second - left) * p.first;
    
    place.insert(p.second);
  }
  
  cout << second_sum << endl;
  
  return 0;
}