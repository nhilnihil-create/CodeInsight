#include <iostream>
using namespace std;
int main(){
  int i,n,result=0;
  int a[100010],b[100010],c[100010];
  cin >> n;
  for(i=0;i<n;i++){
    cin >> a[i];
    a[i]--;
  }
  for(i=0;i<n;i++){
    cin >> b[i];
  }
  for(i=0;i<n-1;i++){
    cin >> c[i];
  }
  for(i=0;i<n;i++){
    if(i!=n-1 && a[i]+1==a[i+1]){
      result += c[a[i]];
    }
    result += b[a[i]];
  }
  cout << result << endl;
  return 0;
}