#include<iostream>
#include<cstdio>

using namespace std;

int main () {
  int N;
  int A[100];
  double ans=0;

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    ans+=(double)1.0/A[i];
  }

  printf("%.10lf\n", 1.0/ans);
}