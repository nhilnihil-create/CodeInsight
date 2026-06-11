#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int main(){

  int m;
  cin >> m;
  long long s=0,l=0;

  for(int i=0;i<m;i++){
    long long int a,b;
    cin >> a >> b;
    s+=a*b;
    l+=b;
  }
  cout << (s-1)/9+l-1 << endl;
  

}