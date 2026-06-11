#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
using namespace std;

int main(){
  int n;
  complex<int> c;
  vector< complex<int> > v;
  vector<int> srt;

  while( cin>>n ){
    if( v.size()==0 ){
      c.real() = n;
      c.imag() = 1;
      v.push_back( c );
      //      cout << "push_back : "<< n << endl;
    }else{
      for( unsigned int i=0;i<v.size();i++ ){
	if( v[i].real()==n ){
	  //	  cout << "coindance : "<<n << endl;
	  v[i].imag()++;
	  break;
	}
	if( i==v.size()-1 ){
	  c.real() = n; c.imag()=1;
	  v.push_back( c );
	  //	  cout << "push_back : "<< n << endl;
	  break;
	}
      }
    }
  }

  int mx = -1;
  for( unsigned int i=0;i<v.size();i++ ){
    //    cout << v[i].real()<<" "<<v[i].imag() << endl;
    mx = max( v[i].imag(), mx );
  }

  srt.clear();
  for( unsigned int i=0;i<v.size();i++ ){
    if( v[i].imag()==mx )
      srt.push_back( v[i].real() );
  }

  sort( srt.begin(), srt.end() );
  for( unsigned int i=0;i<srt.size();i++ )
    cout << srt[i] << endl;

  return 0;
}