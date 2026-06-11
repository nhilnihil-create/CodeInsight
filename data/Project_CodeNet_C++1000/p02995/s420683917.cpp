#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
#include<functional>
#include<deque>
#include<list>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
long long int gcd(long long a,long long b){
  if(b==0){
    return a;
  }
  else{
    return gcd(b,a%b);
  }
}
long long int lcm(long long a,long long b){
  return a/gcd(a,b)*b;
}
int main(){
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  ll e=lcm(c,d);
  a--;
  cout << (b-a)-((b/c+b/d-b/e)-(a/c+a/d-a/e)) << endl;
  return 0;
}