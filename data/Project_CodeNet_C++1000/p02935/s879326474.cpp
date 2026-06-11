#include<bits/stdc++.h>
using namespace std;

int main(){
 int N;
  cin >> N;
  priority_queue<double,vector<double>,greater<double>> Q;
  for(int i=0;i<N;i++){
    double A;
    cin >> A;
    Q.push(A);
  }
  for(int i=0;i<N-1;i++){
    double A=Q.top();
    Q.pop();
    double B=Q.top();
    Q.pop();
    Q.push((A+B)/2);
  }
  cout << fixed << setprecision(10) << Q.top() << endl;
}