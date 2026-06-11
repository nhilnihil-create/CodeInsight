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
#include <numeric>
#include <math.h>
using namespace std;

long euclidean_gcd(long a, long b) {
  while(1) {
    if(a < b) swap(a, b);
    if(!b) break;
    a %= b;
  }
  return a;
}

int main(void){
    long A,B,C,D;
    cin >> A >> B >> C >> D;
    
    long C_N = (B/C) - ((A-1)/C);
    long D_N = (B/D) - ((A-1)/D);
    long CD = C*D / euclidean_gcd(C,D);
    long CD_N = (B/CD) - ((A-1)/CD);

    cout << (B -(A-1)) - (C_N + D_N - CD_N) << endl;
    return 0;
}