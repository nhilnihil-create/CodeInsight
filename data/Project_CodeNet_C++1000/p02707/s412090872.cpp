#include <bits/stdc++.h>
using namespace std;
int main() {
 int a;
  cin>>a;
  vector <int> v(a+1);
  int tmp;
  for (int i=0; i<a-1;i++){
    cin >>tmp;
    v.at(tmp)=v.at(tmp)+1;
  }
  for (int i=1; i<=a;i++){
    cout << v.at(i)<<endl;
  }
}
