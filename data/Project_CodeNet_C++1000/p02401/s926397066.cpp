#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
  int a,b;
  char op;
  //cin >> a >> op >> b;
  while(1){
    cin >> a >> op >> b;
    //cout << a << " " << op <<" " << b<< endl;
    if(op == '+'){
      cout << a + b << endl;
    }else if(op == '-'){
      cout << a - b << endl;
    }else if(op == '*'){
      cout << a * b << endl;
    }else if(op == '/'){
      cout << a / b << endl;
    }else{
      break;
    }
  }
  return 0;
}

