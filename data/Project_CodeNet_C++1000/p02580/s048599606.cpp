#include <bits/stdc++.h>

using namespace std;

const int nax = 3e5+5;

struct pair_hash {
    inline long long operator()(const std::pair<int,int> & v) const {
        return (long long)v.first*nax+v.second;
    }
};

int main() {
  int h, w, m, x, y;
  unordered_set<pair<int, int>, pair_hash> set;
  cin >> h >> w >> m;
 	vector<int> r(h, 0), c(w, 0);
  while(m--) {
    cin >> x >> y;
    x--, y--;
    r[x]++, c[y]++;
    set.insert({x,y});
  }
  int mh = -1, mw = -1;
  vector<int> mvh, mvw;
  for(int i = 0; i < h; i++) {
  	if(mh < r[i]) mh = r[i];
  }
  for(int i = 0; i < h; i++) {
  	if(r[i] == mh) {
      mvh.push_back(i);
    }
  }
  for(int i = 0; i < w; i++) {
  	if(mw < c[i]) mw = c[i];
  }
  for(int i = 0; i < w; i++) {
  	if(c[i] == mw) {
      mvw.push_back(i);
    }
  }
  for(auto x : mvh) {
  	for(auto y : mvw) {
  	    //cout << x << ' ' << y << endl;
    	if(set.find({x,y}) == set.end()) {
        	cout << r[x]+c[y];
          	return 0;;
        }
    }
  }
  cout << r[mvh[0]] + c[mvw[0]] - 1;
	return 0;
}