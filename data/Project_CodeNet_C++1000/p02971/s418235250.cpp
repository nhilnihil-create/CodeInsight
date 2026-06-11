#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;	cin >> n;
  vector<int>	a(n);
  for(int i=0;i<n;i++)	cin >> a[i];
  
  priority_queue<int,vector<int>,less<int>>	data;
  for(int i:a)	data.push(i);
  for(int i=0;i<n;i++){
    int x=data.top();
    if(a[i]!=x)	cout << x << endl;
    else{
      data.pop();
      cout << data.top() << endl;
      data.push(x);
    }
  }
}