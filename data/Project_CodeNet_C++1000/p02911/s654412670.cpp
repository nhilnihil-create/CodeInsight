#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;


int main(){
  long long n, k, q;
  cin >> n >> k >> q;
  vector<long long> a(q);
  for(int i = 0; i < q; i++){
    cin >> a[i];
  }
  vector<long long> s(n);
  for(int i = 0; i < n; i++) s[i] = k - q;
  for(int i = 0; i < q; i++) s[a[i] - 1]++;
  for(int i = 0; i < n; i++){
    if(s[i] > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}