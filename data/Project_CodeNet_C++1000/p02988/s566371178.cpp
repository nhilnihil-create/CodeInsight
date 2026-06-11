#include <bits/stdc++.h>
#define FOR(i, n) for(ll i = 0; i < n; i++)
#define FORR(i, n) for(ll i = n; i >= 0; i--)
#define FORS(i, m, n) for(int i = m;i < n;i++)
#define ALL(v) accumulate(v.begin(),v.end(),0)
#define SORT(v) sort(v.begin(),v.end())
#define OUT(n) (cout << n << endl)
#define IN1(a) (cin >> a)
#define IN2(a,b) (cin >> a >> b)
#define IN3(a,b,c) (cin >> a >> b >> c)
#define IN4(a,b,c,d) (cin >> a >> b >> c >> d)
#define REVS(v) reverse(v.begin(),v.end())
#define PI 3.14159265359
using namespace std;
typedef long long ll;
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
  int n;
  IN1(n);
  vector<int>aarray(n);
  FOR(i,n){
    cin >> aarray.at(i);
  }
  int ans=0;
  FORS(i,1,n-1){
    if (((aarray[i-1] > aarray[i]) && (aarray[i] > aarray[i+1])) || ((aarray[i-1] < aarray[i]) && (aarray[i] < aarray[i+1]))){
      ans++;
    }
  }
  OUT(ans);
}