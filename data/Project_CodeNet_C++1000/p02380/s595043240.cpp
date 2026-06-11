#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef vector<string> vs;
#define ifr(i,n) for((i)=0;(i)<(n);i++)
#define dfr(i,n) for((i)=(n);(i)>=0;i--)
int main(){
  int a,b,C;
  cin >> a >> b >> C;
  double S=0.5*a*b*sin(2*M_PI*C/360);
  double L;
  double l=sqrt(-2*a*b*cos(2*M_PI*C/360)+a*a+b*b);
  L=a+b+l;
  double h=2*S/a;
  printf("%.8lf\n%.8lf\n%.8lf\n",S,L,h);
  return 0;
}