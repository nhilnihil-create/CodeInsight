#include <iostream>
using namespace std;
typedef long long ll;
int main(){
  ll w,h,x,y,a=0;cin>>w>>h>>x>>y;
  if(x*2==w&&y*2==h){a++;}
  cout << (double)w*(double)h/2.00<<" "<<a<<endl;
}
