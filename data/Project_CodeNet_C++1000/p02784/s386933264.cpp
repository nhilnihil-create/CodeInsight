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
  int a, b, c = 0;
  cin >> a>> b;
  rep(i, 0, b){
    int d;
    cin >> d;
    c += d;
  }
  if(c >= a){
    cout << "Yes\n";
  }
  else{
    cout << "No\n";
  }
}