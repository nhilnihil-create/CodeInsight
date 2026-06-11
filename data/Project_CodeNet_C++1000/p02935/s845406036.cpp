#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;	cin >> n;
  priority_queue<double, vector<double>, greater<double>>	v;
  for(int i=0;i<n;i++){
    double x;	cin >> x;
    v.push(x);
  }
  
  for(int i=0;i<n-1;i++){
    double x=v.top();	v.pop();
    double y=v.top();	v.pop();
    v.push((x+y)/2);
  }
  printf("%.10f",v.top());
}