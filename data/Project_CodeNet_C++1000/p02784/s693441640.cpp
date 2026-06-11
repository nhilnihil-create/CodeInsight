#include<iostream>
#include<string>
using namespace std;
int main(){
  int c, n, s = 0;
  cin >> c >> n;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
    s = s+ a[i];
  }
  if(s >= c){
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";
}