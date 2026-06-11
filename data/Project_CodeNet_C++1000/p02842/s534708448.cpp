#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  cout << setprecision(10);
  int N;
  cin >> N;
  for(int i = 0; i <= 50000; i++){
    int x = (double)(i) * 1.08;
    if(N == x){
      cout << i << endl;
      return 0;
    }
  }
  cout << ":(" << endl;
}
