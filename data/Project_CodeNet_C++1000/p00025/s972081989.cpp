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
  int a[2][4];
  while(cin>>a[0][0]){
    rep(i,3)cin>>a[0][i+1];
    rep(i,4)cin>>a[1][i];
    int co[2]={0};
    rep(i,4)rep(j,4){
      if(a[0][i]==a[1][j]&&i==j)co[0]++;
      else if(a[0][i]==a[1][j])co[1]++;
    }
    cout<<co[0]<<" "<<co[1]<<endl;
  }
}