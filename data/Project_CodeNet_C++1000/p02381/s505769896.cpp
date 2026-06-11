#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define it ::iterator
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double ESP=1e-10;
using namespace std;
int main(){
  int n;
  while(cin>>n,n){
    double a=0,b=0;
    rep(i,n){
      int tmp;cin>>tmp;
      a+=tmp*tmp;
      b+=tmp;
    }
    a/=n;
    b/=n;
    b*=b;
    printf("%.10f\n",sqrt(abs(a-b)));
  }
}