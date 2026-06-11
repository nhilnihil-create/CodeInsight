#include <bits/stdc++.h> 
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
int main(){
  int x,y,l=0;
  cin>>x>>y;
  if(x<=3){l+=400000-100000*x;}
  if(y<=3){l+=400000-100000*y;}
  if(x==1&&y==1){l+=400000;}
  cout<<l<<endl;
}