//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_10_C
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
  int n;
  while(cin >> n){
    if(n == 0) break;
    double S[n];
    for(int i=0; i<n; i++){
      cin >> S[i];
    }
    //??????????±???????
    double median = 0;
    for(int i=0; i<n; i++){
      median += S[i];
    }
    median /= n;
    //?¨??????????????±???????
    double stddev = 0;
    for(int i=0; i<n; i++){
      stddev += (S[i]-median)*(S[i]-median);
    }
    stddev /= n;
    stddev = sqrt(stddev);
    printf("%.9lf\n", stddev);
  }
}