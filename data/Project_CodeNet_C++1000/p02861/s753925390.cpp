#include <stdio.h>		// standard input output
#include <iostream>		// input output stream, cin cout( console in console out)
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>		// input output manipulation
#include <cmath>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long 

int main() {
  int N;
  cin >> N;
  vector<int> x(N),y(N),v(N);
  rep(i,N){
	cin >> x.at(i) >> y.at(i);
    v.at(i) = i;
  }
  double dist = 0, x_dist, y_dist;
  int N_kaijo = 0;
  do{
    N_kaijo++;
	rep(i,N-1){
      x_dist = x.at(v.at(i))-x.at(v.at(i+1));
      y_dist = y.at(v.at(i))-y.at(v.at(i+1));
      dist += sqrt(x_dist*x_dist + y_dist*y_dist);
    }
  }while(next_permutation(v.begin(),v.end()));
     
  cout << setprecision(12) << dist/N_kaijo << endl; // 標準出力
}