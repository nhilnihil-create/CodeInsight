#include <iostream>
using namespace std;
typedef long long ll;

int main () {
  int N;
  cin>>N;
  int a[100];
  for (int i=0; i<N; i++) {
    cin >> a[i];
  }
  ll sum=0;
  for (int i=0; i<N; i++) {
    for (int j=i+1; j<N; j++) {
      sum+=a[i]*a[j];
    }
  }
  cout << sum << endl;
}