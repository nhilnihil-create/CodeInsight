#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll w,h,x,y;
  cin >> w >> h >> x >> y;
  cout << w*h/2;
  if((w*h)%2==1){
    cout << ".5";
  }
  
  cout << " ";
  if(x*2==w&&y*2==h){
    cout << 1 << endl;
  }else{
    cout << 0 << endl;
  }
}