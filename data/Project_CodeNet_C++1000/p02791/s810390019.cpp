#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long 
string m[21][21];

vector<vector<int>> dxy = {{1,0},{-1,0},{0,-1},{0,1}};
deque<pair<int,int>> dq;

int main() {
  priority_queue<int,vector<int>,greater<int> > pq;
  int n ;
  cin >> n;
  int p[n];
  for(int i = 0;i<n;i++){
    cin >> p[i];
  }
  int res = 1;
  pq.push(p[0]);
  for(int i = 1 ; i< n; i++){
    if(p[i] <= pq.top()){ res++;}
    pq.push(p[i]);
  }
  
  cout << res << endl;
 }