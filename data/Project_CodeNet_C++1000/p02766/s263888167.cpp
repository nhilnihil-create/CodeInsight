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
  ll int k, n, sm = 0;
  cin >> n >> k;
  do{
    sm++;
    //int a = n % k;
    n = n / k;
    if(n == 1){
      sm++;
      break;
    }
  }while(n != 0);
    
    cout << sm << "\n";
}