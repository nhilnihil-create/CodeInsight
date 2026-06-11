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
double a;
int s[1000];
double n;
double m;
double sum;
int main()
{
  while(cin >>n,n){
    sum = 0;
    a = 0;
    for(int i = 0;i <n;i++){
      cin >>s[i];
      sum +=s[i];
    }
    m =sum/n;
    for(int i = 0;i <n;i++){
      a +=(s[i]-m)*(s[i]-m);
    }
    a =a/n;
    a =sqrt(a);
    cout <<fixed<<setprecision(10)<<a<<endl;
  }
  return 0;
}