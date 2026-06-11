#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cctype>
#define rep(i,a,b) for(int i=(a);i<b;i++)
#define INF 1000000000
#define MAX_N 100000000
using namespace std;
bool debug=false;

int main(){
  double a,b,c,d;
  cin>>a>>b>>c>>d;
  printf("%.7f\n",sqrt(pow(a-c,2)+pow(b-d,2)));
  return 0;
}