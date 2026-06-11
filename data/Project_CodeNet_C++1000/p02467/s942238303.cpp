#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cctype>
#define rep(i,a,b) for(int i=(a);i<b;i++)
#define INF 1000000000
#define MAX_N 100000000
using namespace std;
bool debug=false;

int main(){
  int n;
  cin>>n;
  cout<<n<<":";
  while(n%2==0){
    cout<<" "<<2;
    n/=2;
  }
  for(int i=3;i<=sqrt(n);){
    if(n%i==0){
      cout<<" "<<i;
      n/=i;
    }else{
      i+=2;
    }
    if(n==1)break;
  }
  if(n!=1)cout<<" "<<n<<endl;
  else cout<<endl;
  return 0;
}