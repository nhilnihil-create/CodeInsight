#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
using namespace std;
int inf = 1000000000;

long long count(vector<int> &a){
  long long cnt = 0;
  int n = a.size();

  if( n > 1 ){
    vector<int> b(a.begin(), a.begin()+n/2);
    vector<int> c(a.begin()+n/2, a.end());
    cnt += count(b);
    cnt += count(c);
    for(int i=0, j=0, k=0; i<n; i++){
      if( k == c.size() ) a[i] = b[j++];
      else if( j == b.size() ) a[i] = c[k++];
      else if( b[j] <= c[k] ) a[i] = b[j++];
      else{ a[i] = c[k++]; cnt += n/2 - j; }
    }
  }
  return cnt;
}

int main(void) {

  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  cout << count(a) << endl;
  return 0;
}

// EOF