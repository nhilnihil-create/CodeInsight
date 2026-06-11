#include <iostream>
#include <algorithm>
#include <string>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int n;
  long long sum=0,max,min,a;
  cin >> n;
  REP(i,n){
    cin >> a;
    sum+=a;
    if(i==0){
      max=a;
      min=a;
    }
    if(max<a)
      max=a;
    if(min>a)
      min=a;
  }
  cout << min <<' '<< max <<' '<< sum << endl;
}