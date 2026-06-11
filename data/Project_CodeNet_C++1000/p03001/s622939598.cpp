#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define ll long long
int main() {
    int W,H,x,y;
    cin>>W>>H>>x>>y;
  double r=double(W)*double(H)/2*(1.0);
  int c=0;
  if(x*2==W && y*2==H) c=1;
  cout<<fixed<<setprecision(6)<<r<<" "<<c<<endl;
}