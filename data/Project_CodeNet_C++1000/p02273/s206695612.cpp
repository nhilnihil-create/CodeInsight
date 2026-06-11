#include <cassert>
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <set>
#include <limits>
#include <numeric>
#include <iterator>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  
  int n; //1 .. 6
  cin >> n;

  vector<pair<double, double> > koch = {{0.,0.}, {100., 0.}};

  for(int i = 0; i < n; ++i){
    vector<pair<double, double> > new_koch;
    for(unsigned int j = 0; j < koch.size()-1; ++j){
      const auto s = koch[j], t = koch[j+1];
      const double 
	sin = sqrt(3)/2.0,
	cos = 1./2.;
      const double 
	dx = t.first  - s.first,
	dy = t.second - s.second;
      
      pair<double, double> q1, q2, q3;
      q1 = make_pair( dx/3. + s.first,  dy/3. + s.second);
      q3 = make_pair(-dx/3. + t.first, -dy/3. + t.second);
      q2 = make_pair(q1.first + dx*cos/3. -dy*sin/3., 
		     q1.second+ dx*sin/3. +dy*cos/3.);

      new_koch.push_back(s);
      new_koch.push_back(q1);
      new_koch.push_back(q2);
      new_koch.push_back(q3);
      //new_koch.push_back(t);
    }
    new_koch.push_back(make_pair(100.,0.));
    koch = new_koch;
  }
  
  //output
  for(auto p : koch){
    cout << fixed
	 << setprecision(8) << p.first << " " 
	 << setprecision(8) << p.second <<endl;
  }

  return 0;
}