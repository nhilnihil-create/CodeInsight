#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
typedef pair<int,int> P;

const double PI=3.14159265358979; 
int main(){
  int a,b,h,m;
  cin>>a>>b>>h>>m;
  int MIN=h*60+m;
  double j=abs(MIN*PI/360-MIN*PI/30);
  cout<<fixed<<setprecision(11)<<sqrt(a*a+b*b-2*a*b*cos(j))<<endl;
return 0;
}