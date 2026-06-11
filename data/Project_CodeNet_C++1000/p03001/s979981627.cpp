#include <bits/stdc++.h>
using namespace std;
#define	rep(i,n)	for(int i=0;i<n;i++)
int main(){
  long long w,h,x,y;	cin >> w >> h >> x >> y;
  cout << (double)w*(double)h/2.0 << endl;
  if(x*2==w&&y*2==h)	cout << 1;
  else cout << 0;
}