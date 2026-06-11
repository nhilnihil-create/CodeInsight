#include <iostream>
#include <map>
using namespace std;
int main( void )
{
  ios::sync_with_stdio(false);
  while( 1 ){
    int N, M, a;
    int d[2048];
    map<int,int> h,v;
    cin >> N >> M;
    if( N == 0 && M == 0 ) break;
    d[0] = 0;
    for( int i=0; i<N; i++ ){
      cin >> a;
      d[i+1] = d[i] + a;
    }
    for( int i=0; i<=N; i++ ){
      for( int j=i+1; j<=N; j++ ){
        h[d[j]-d[i]]++;
      }
    }
    d[0] = 0;
    for( int i=0; i<M; i++ ){
      cin >> a;
      d[i+1] = d[i] + a;
    }
    for( int i=0; i<=M; i++ ){
      for( int j=i+1; j<=M; j++ ){
        v[d[j]-d[i]]++;
      }
    }
    int ret = 0;
    for( map<int,int>::iterator it = h.begin(); it != h.end(); ++it ){
      ret += it->second * v[it->first];
    }
    cout << ret << endl;
  }
}