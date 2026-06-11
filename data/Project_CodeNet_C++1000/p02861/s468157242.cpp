#include <bits/stdc++.h>
using namespace std;

long double func(long long n,long long x){
  if(n == 1){return x;}
  else{return func(n-1,x*n);}
}
            
int main(){
  long long n;
  cin >> n;
  vector<pair<long long,long long>> a(n);
  for(int i=0;i < n;i++){
    int x, y;
    cin >> x >> y;
    a.at(i) = make_pair(x, y);
  }
  long double x = func(n,1);
  long double sum = 0;
  for(int i=0;i < x;i++){
  	next_permutation(a.begin(),a.end());
    for(int j=1;j < n;j++){
      //cout << a.at(j-1).first << "," << a.at(j-1).second ;
      sum += sqrt((a.at(j-1).first - a.at(j).first)*(a.at(j-1).first - a.at(j).first) + (a.at(j-1).second - a.at(j).second)*(a.at(j-1).second - a.at(j).second));
    }
    //cout << a.at(n-1).first << "," << a.at(n-1).second;
    //cout << sum << endl;
  }
  long double ans = sum / x ;
  cout << setprecision(12) << ans << endl;
}