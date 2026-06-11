#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define pi 3.14159265358979323846
#define ll long long
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27, 28, 30, 32, 35, 36, 40, 42, 45, 49, 56, 63, 64, 72, 81};
  int n;
  cin >> n;
  rep(i, 0, 34){
    if(n == v[i]){
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No";
}
  
  
  