#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
  while(1){
    int n;
    cin >> n;
    if (n == 0) break;

    int A[1000]={0};
    int sum = 0;

    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) sum += A[i];
    double avg = 1.0*sum/n;
    double dist = 0.0;
    for (int i = 0;  i < n; i++) {
      dist += (avg - A[i])*(avg - A[i]);
    }
    printf("%.8f\n", sqrt(dist/n));
  }
  return 0;
}