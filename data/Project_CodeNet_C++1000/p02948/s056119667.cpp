#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <iostream>
#include <ctype.h>
#include <string>
typedef long long ll;
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector <pair<int, int >> pair(n);
  rep(i,n){
    cin>>pair[i].first>>pair[i].second;
  }
    
  sort(pair.begin(), pair.end());   
  //cout<<pair[0].second;
  ll sum=0;     
  priority_queue<int> salary;
  int j=0;
  for(int i=1; i<m+1; i++){
    for( j; pair[j].first<=i; j++){
      salary.push(pair[j].second);
    }
    if(salary.empty()) continue;
    else{
      sum+=salary.top();
      salary.pop();
    }
  }
  
  cout<<sum;
}