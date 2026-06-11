#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N;
  cin >> N;
  long double tmp = 0;
  long double sum = 0;
  for(int i = 0; i < N; i++){
    cin >> tmp;
    sum += 1/tmp;
  }
  cout << 1/sum << endl;
}
