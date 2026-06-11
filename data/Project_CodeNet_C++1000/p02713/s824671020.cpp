#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;

    for(int i=1;i<n+1;i++){
      for(int j=1;j<n+1;j++){
        for(int k=1;k<n+1;k++){
          count +=__gcd(__gcd(i,j),__gcd(j,k));
        }
      }
    }
  cout << count << endl;
}