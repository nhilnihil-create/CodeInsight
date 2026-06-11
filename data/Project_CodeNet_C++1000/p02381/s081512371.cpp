#include<cstdio>
#include<iostream>
#include<cctype>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define ll long long
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define MD 1000000007

char sep[3] = " \n";
int i, j, k, l, m, n;
double PI = acos(-1);


int main() {
  int s[1010];

  while(true) {
    cin >> n;
    if (n == 0) break;
    double mean = 0.0;
    rep(i,n) cin >> s[i], mean+=s[i];
    mean/=n;
    double sigma = 0.0;
    rep(i,n) sigma += (s[i]-mean)*(s[i]-mean);
    sigma = sqrt(sigma/n);
    printf("%.5f\n", sigma);
  }

  return 0;
}
  