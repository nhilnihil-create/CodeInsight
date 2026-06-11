#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    int count = 0;
    int num = 0;
    vector <int> vec(a);
    for(int i = 0;i<a;i++){
      cin >> vec.at(i);
      count += vec.at(i);
    }
    for(int i = 0;i<a;i++){
      if((vec.at(i)*4*b)>=count)num++;
    }
  if(num>=b) cout << "Yes" << endl;
  else cout << "No" << endl;
}