#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctype.h>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

//4方向ベクトル→↑←↓
int dx[] ={1,0,-1,0};
int dy[] ={0,-1,0,1};

double x,x2;
double y,y2;
double d;

int main()
{
  cin >>x>>y>>x2>>y2;
  cout <<setprecision(10)<<sqrt(pow(x-x2,2)+pow(y-y2,2))<<endl;
  return 0;
}