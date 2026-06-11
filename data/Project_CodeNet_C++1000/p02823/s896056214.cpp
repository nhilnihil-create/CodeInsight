#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define Rep(i,n) for(intl i=0;i<(intl)(n);i++)
#define Rep1(i,n) for(intl i=1;i<(intl)(n)+1;i++)
#define vec vector
#define fi first
#define se second
#define pushb push_back
#define popb pop_back
#define SortA(v) sort(v.begin(), v.end())
#define SortD(v) sort(v.rbegin(), v.rend())
using intl = int64_t;
using vi = vec<intl>;
using vvi = vec<vi>;
vec<intl> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vec<intl> dy = {1, 0, -1, 0, 1, -1, 1, -1};

int main(){
  intl N,A,B;
  cin >>N>>A>>B;
  if( (A-B)%2==0 ) { cout<<(B-A)/2;return 0;}
  
  intl ifmax;
  intl ifmin;
  
  ifmax = A + (B-A -1)/2;
  ifmin = N-B+1 + (N -( A+(N-B+1) ) )/2;
  cout << min(ifmax,ifmin);
}
  