#include <bits/stdc++.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef long double ld;
//#define rep(i, a, b) for(ll i = ll(a); i <= ll(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)


int main(){

 int n;
 cin>>n;

 vector<int>a(n);

 rep(i,n)
 cin>>a[i];

 vector<double>AI(n);

 rep(i,n)
  AI[i] = 1/double(a[i]);

 double sum =0;
 rep(i,n)
  sum += AI[i];

  sum = 1.0/sum;

  cout<<setprecision(10);
  cout<<sum<<endl;

return 0;
}

