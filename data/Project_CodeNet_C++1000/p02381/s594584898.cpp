#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>

using namespace std;

int main () {
  int n;
  while(cin >> n, n != 0 ) {
    int data[1000];
    int sum = 0;
    for(int i = 0; i < n ; i++){
      int r;
      cin >> r;
      data[i] = r;
      sum += r;
      
    }
    double avg = (double)sum / (double)n;
    double ss = 0;
    for(int i = 0; i < n ; i++){
      ss += pow((double)data[i] - avg, 2);
    }
    printf("%.6f\n", sqrt(ss/(double)n));


  }


}