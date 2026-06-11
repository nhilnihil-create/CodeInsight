#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
//int l[n+1];
int main() {
  int n;
  cin >>n;
  priority_queue<long double,vector<long double>,greater<long double>>pq;
  int tmp;
  for(int i = 0;i<n;i++){
    cin >> tmp;
    pq.push(tmp);
  }

  long double a,b;
  for(int i=0;i<n-1;i++){
    a = pq.top();
    pq.pop();
    b = pq.top();
    pq.pop();
    pq.push((a+b)/2);
    //cout << a << " " << b<< endl;
  }
  
  cout << fixed << setprecision(10);
  cout << pq.top();
}
