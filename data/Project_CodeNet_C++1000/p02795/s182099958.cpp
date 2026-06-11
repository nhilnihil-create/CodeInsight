#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int h,w,n,m;cin >> h >> w >> n;m = max(h,w);
  cout << ((n%m==0) ? n/m:n/m+1) << endl;
}