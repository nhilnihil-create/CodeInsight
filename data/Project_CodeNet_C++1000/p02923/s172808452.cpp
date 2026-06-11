#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;	cin >> n;
  queue<int>	h;
  for(int i=0;i<n;i++){
    int x;	cin >> x;
    h.push(x);
  }
  
  int ans=0;
  int height=h.front();	h.pop();
  int now=height;
  int count=0;
  while(!h.empty()){
    int x=h.front();	h.pop();
    if(x<=now)	count++;
    if(now<x)	count=0;
    now=x;
    ans=max(ans,count);
  }
  cout << ans;
}