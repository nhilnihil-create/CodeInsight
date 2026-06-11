#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1,0,-1,0},dy[] = {0,1,0,-1};
using pii = pair<int,int>;
int func(int a){
  return a+a*a+a*a*a;
}
int main(){
  int n;
  cin>>n;
  cout << func(n) << endl;
}