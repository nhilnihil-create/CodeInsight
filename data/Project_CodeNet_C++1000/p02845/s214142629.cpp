#include<bits/stdc++.h>
using namespace std;

int main() {
  long long int count=1;
  int n;
  int x=0,y=0,z=0;
  cin >> n;
  for (int i=0; i<n; i++) {
    int num;
    cin >> num;
    int temp_count=0;
    if (x==num) {
      temp_count++;
      x++;
      if (y==num) {
        temp_count++;
      }
      if (z==num) {
        temp_count++;
      }
    }
    else if (y==num) {
      temp_count++;
      y++;
      if (z==num) {
        temp_count++;
      }
    }
    else if (z==num) {
      temp_count++;
      z++;
    }
    count *= temp_count;
    count %= 1000000007;
  }
  cout << count;
}
