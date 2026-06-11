#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
#include<map>
#include<bitset>
#include<queue>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;

  n = n % 1000;
  if (n != 0){
    n = abs(n - 1000);  
  }

  cout << n << endl;
}
