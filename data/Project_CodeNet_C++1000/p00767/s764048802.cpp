#include<iostream>
#include<algorithm>
using namespace std;

bool isGreater(int h, int w, int hh, int ww){
  if ( h*h + w*w == hh*hh + ww*ww ) return h < hh;
  else return h*h + w*w < hh*hh + ww*ww;
}

void solve(int h, int w){
  int mh = 151;
  int mw = 151;
  for ( int hh = 1; hh < 150; hh++ ){
    for ( int ww = hh+1; ww <= 150; ww++ ){
      if (isGreater(h, w, hh, ww) && !isGreater(mh, mw, hh, ww) ){
	mh = hh;
	mw = ww;
      }
    }
  }
  cout << mh << " " << mw << endl;
}

main(){
  int h, w;
  while(1){
    cin >> h >> w;
    if ( h == 0 && w == 0 ) break;
    solve(h, w);
  }
}