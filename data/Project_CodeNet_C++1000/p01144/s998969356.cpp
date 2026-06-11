#include <iostream>
using namespace std;
int main(){
  long long int m;
  int n, d[10000];
  short p[10000];
  bool f;

  while( cin>>n>>m && (n||m) ){
    for( int i=0;i<n;i++ )
      cin >> d[i] >> p[i];

    do{
      f=false;
      for( int i=1;i<n;i++ )
	if( p[i-1]<p[i] ){
	  int dd=d[i]; d[i]=d[i-1]; d[i-1]=dd;
	  short pp=p[i]; p[i]=p[i-1]; p[i-1]=pp;
	  f=true;
	}
    }while( f );

    long long int ans=0;
    for( int i=0;i<n;i++ ){
      if( m>0 ){
	m-=d[i];
	if( m<0 ){
	  d[i] = -m; m=0;
	  ans += d[i]*p[i];
	}
      }else if( !m )
	ans += d[i]*p[i];      
    }
    cout << ans << endl;
  }
  return 0;
}