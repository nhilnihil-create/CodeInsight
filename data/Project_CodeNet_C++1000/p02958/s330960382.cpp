#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;	cin >> n;
  vector<int>	p(n);
  for(int i=0;i<n;i++)	cin >> p[i];
  
  vector<int>	q=p;
  sort(q.begin(),q.end());
  
  int cnt=0;
  for(int i=0;i<n;i++){
    if(p[i]!=q[i])	cnt++;
  }
  if(cnt==2||cnt==0)	cout << "YES";
  else	cout << "NO";
}