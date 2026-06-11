#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
using namespace std;
int cnt = 0;
vector<int> tmp;
vector<int> insert(vector<int> a, int n, int g){
  for(int i=g; i<n; i++){
    int v = a[i];
    int j = i - g;
    while( j >= 0 && a[j] > v ){
      a[j+g] = a[j];
      j -= g;
      cnt++;
    }
    a[j+g] = v;
  }
  return a;
}
vector<int> shell(vector<int> a, int n){
  int m = n;
  while( m != 0 ){
    tmp.push_back(m);
    a = insert(a, n, m);
    m /= 2;
  }
  return a;
}


int main(void) {
  int n;
  cin >> n;
  vector<int> s(n);
  for(int i=0; i<n; i++) cin >> s[i];
  s = shell(s, n);
  cout << tmp.size() << endl;
  for(int i=0; i<tmp.size()-1; i++) cout << tmp[i] << " ";
  cout << tmp[tmp.size()-1] << endl;
  cout << cnt << endl;
  for(int i=0; i<n; i++) cout << s[i] << endl;
  return 0;
}





// EOF