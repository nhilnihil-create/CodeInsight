#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>
using namespace std;


int main(void){
  long double L;
  cin >> L;
  cout << std::fixed <<  std::setprecision(7) <<  pow(L/3,3) << endl;
  return 0;
}