#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  double w,h,x,y;
  cin >> w >> h >> x >> y;

  if(w==2*x && h==2*y){
    printf("%0.12f",w*h/2);
    cout << " " << 1 << endl;
  }
  else{
    printf("%0.12f",w*h/2);
    cout << " " << 0 << endl;
  }

}