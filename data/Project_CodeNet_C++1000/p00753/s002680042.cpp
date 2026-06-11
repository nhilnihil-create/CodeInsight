#include <iostream>
#define N 2*123460

using namespace std;

int main(){
  int n;
  bool q[N];

  q[0] = false; q[1]=false;
  for( int i=2;i<N;i++ ) q[i]=true;

  for( int i=2;i<N;i++ ){
    if( q[i] ){
      for( int j=2*i;j<N;j+=i )
	if( j%i==0 )
	  q[j] = false;
    }
  }

  while( cin>>n , n ){
    int c=0;
    for( int i=n+1,len=2*n;i<=len&&i<N;i++ ){
      if( q[i] )c++;
    }
    cout << c << endl;
  }

  return 0;
}