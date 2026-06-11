#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  int d[N];
  for(int i=0;i<N;i++){
    cin >> d[i];
  }
  sort(d,d+N);
  cout << d[N/2]-d[N/2-1]<< endl;
}
