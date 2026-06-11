#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  for(int i =0; i < 5; i++){
    int tmp; cin >> tmp;
    if(tmp==0){
      cout << i+1 << endl;
      return 0;
    }
  }
}
