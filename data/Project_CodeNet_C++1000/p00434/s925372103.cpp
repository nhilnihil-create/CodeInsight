#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

#define rep(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(itr,c) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

int main(){
  int i;
  bool f[31];

  rep(i,31) if(i != 0) f[i] = false;
  rep(i,28){
    int num;
    scanf("%d",&num);
    f[num] = true;
  }

  rep(i,31) if(i != 0 && !f[i]) cout << i << endl;

  return 0;
}