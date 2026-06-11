#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iterator>
#include <numeric>
#include <functional>
#include <climits>



using namespace std;
typedef unsigned long long ull;
typedef long long ll;

size_t n;
vector<int> a;

bool f(size_t i, int m){
  if(m == 0){
    return true;
  }
  if(i == n-1){
    return m == a[i];
  }
  return f(i+1, m) || f(i+1, m-a[i]);
}


int main(int argc, char *argv[]){
  cin >> n;
  a.resize(n);
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }

  size_t q;
  cin >> q;
  for (size_t i = 0; i < q; i++) {
    int m;
    cin >> m;
    if(f(0, m)){
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
    
  }

  

  
  
  return 0;
}