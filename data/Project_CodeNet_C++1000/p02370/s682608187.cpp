#include<bits/stdc++.h>
using namespace std;
int main(){
  int v,e,s,t,a[10001]={};
  vector<int> vec[10001];
  cin >> v >> e;
  for(int i=0;i<e;i++){
    cin >> s >> t;
    vec[s].push_back(t);
    a[t]++;
  }
  stack<int> st;
  for(int i=0;i<v;i++){
    if(a[i] == 0) st.push(i);
  }
  while(!st.empty()){
    cout << st.top() << endl;
    int p = st.top();
    st.pop();
    for(int i=0;i<vec[p].size();i++){
      a[ vec[p][i] ]--;
      if(a[ vec[p][i] ] == 0) st.push( vec[p][i] );
    }
  }
  return (0);
}