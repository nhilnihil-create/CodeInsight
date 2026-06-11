#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    int64_t n, m;
    double a = 0;
    cin >> n >> m;
    vector<int> vec(n);
    string ans = "No";
  
    for (int i = 0; i < n; i++){
      cin >> vec.at(i);
      a = a + vec.at(i);
    }
  
  a = a/(4 * m);
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  if(a <= vec.at(m-1)) ans ="Yes";
  
  cout <<  ans  << endl;
}