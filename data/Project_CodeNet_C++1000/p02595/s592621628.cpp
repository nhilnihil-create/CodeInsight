#include<bits/stdc++.h>
using namespace std;

#define Vsort(a) sort(a.bigin(), a.end())
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
  long long int n, d;
  long long int a, b, count = 0;
  double c;
  cin >> n >> d;
  vector<long long int> x(n);
  vector<long long int> y(n);
  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }
  for(int i = 0; i < n; i++){
    a = x[i];
    b = y[i];
    c = sqrt((a * a) + (b * b));
    if(c <= d) count++;
  }
  cout << count;
}
