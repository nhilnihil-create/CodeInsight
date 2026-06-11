#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  long int n, sum = 0;
  cin >> n;
  rep(i, 1, n + 1){
    if(i % 3 != 0 && i % 5 != 0){
      sum += i;
    }
  }
  cout << sum << "\n";
}