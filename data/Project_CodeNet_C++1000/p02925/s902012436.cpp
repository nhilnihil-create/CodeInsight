#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;


int main(void){
  int n,i,j,a[1003][1003],k[1003]={};
  
  cin >> n;
  for (i=0;i<n;i++) for (j=0;j<n-1;j++){
    cin >> a[i][j];
    a[i][j]--;
  }
  
  int qs,p,ne,t;
  queue<int> q;
  bool rk=true;
  
  for (i=0;i<n;i++) q.push(i);
  
  t=0;
  while (rk && !q.empty()){
    bool u[1003]={false};
    rk=false;
    qs=q.size();
    for (i=0;i<qs;i++){
      p=q.front();
      q.pop();
      ne=a[p][k[p]];
      if (!u[p] && !u[ne] && a[ne][k[ne]]==p){
        rk=true;
        u[p]=u[ne]=true;
        k[p]++;
        k[ne]++;
        if (k[p]<n-1) q.push(p);
        if (k[ne]<n-1) q.push(ne);
      }
    }
    t++;
  }
  
  for (i=0;i<n;i++){
    if (k[i]<n-1){
      cout << -1 << endl;
      return 0;
    }
  }
  
  cout << t << endl;
  
  return 0;
}