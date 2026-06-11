#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;

ll gcd(int a,int b){
  ll r = a%b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }

  return b;
}

int main(){
  ll a,b; cin >> a >> b;
  if(a<b){
    swap(a,b);
  }

  ll GCD = gcd(a,b);

  cout << a*b/GCD << endl;

}
