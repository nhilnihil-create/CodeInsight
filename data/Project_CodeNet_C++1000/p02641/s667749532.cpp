#include <iostream>
using namespace std;

int main(){
  int x,n,a,tmp;
  int p[102]={0};
  cin >> x >> n;
  if (n ==0){
    cout << x << endl;
    return 0;
  }
  for(int i=0;i<n;i++){
    cin >> tmp;
    p[tmp] += 1;
  }
  for(int i=0;i<=x;i++){
    a = x - i;
    if (p[a] == 0){
      cout << a << endl;
      return 0;
    }
    a = x + i;
    if (p[a] == 0){
      cout << a << endl;
      return 0;
    }
  }
  return 0;
}