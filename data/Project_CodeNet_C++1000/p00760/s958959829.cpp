#include <iostream>
using namespace std;

int main(){
  int n;
  int y,m,d;

  cin >> n;
  while( n-- ){
    cin >> y >> m >> d;
    int ans = 0, len = (y%3!=0&&m%2==0)?19:20;

    while( d<=len ){
      ans++;
      d++;
    }

    m++;
    while( m<=10 ){
      if( y%3==0 )
	ans += 20;
      else{
	if( m%2==1 )
	  ans += 20;
	else
	  ans += 19;
      }
      m++;
    }

    y++;
    while( y<1000 ){
      if( y%3==0 )
	ans += 20 * 10;
      else 
	ans += 20 * 5 + 19 * 5;
      y++;
    }
    cout << ans << endl;
  }

  return 0;
}