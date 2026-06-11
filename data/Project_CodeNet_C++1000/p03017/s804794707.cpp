#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1);


ll N,A,B,C,D;
vector<bool> sunuke;
string S;
bool sunuke_dp(ll n)
{
  //cout<<n<<endl;
  if(S.at(n)=='#') {return false;}
  if(sunuke.at(n)) {return true;}
  if(n-1>=A&&sunuke_dp(n-1))
  {
    sunuke.at(n)=true;
    return true;
  }
  if(n-2>=A&&sunuke_dp(n-2))
  {
    sunuke.at(n)=true;
    return true;
  }
  return false;
}  

vector<bool> hunuke;
bool hunuke_dp(ll n)
{
  if(S.at(n)=='#') {return false;}
  if(hunuke.at(n)) {return true;}
  if(n-1>=B&&hunuke_dp(n-1))
  {
    hunuke.at(n)=true;
    return true;
  }
  if(n-2>=B&&hunuke_dp(n-2))
  {
    hunuke.at(n)=true;
    return true;
  }
  return false;
}  



int main() 
{
  cin>>N>>A>>B>>C>>D; A--; B--; C--; D--; 
  cin>>S;
  sunuke=vector<bool>(N,false);
  hunuke=vector<bool>(N,false);
  sunuke.at(A)=true;
  hunuke.at(B)=true;
  //if(sunuke_dp(C)) {cout<<"s"<<endl;} else{cout<<"sx"<<endl;}
  //if(hunuke_dp(D)) {cout<<"h"<<endl;} else{cout<<"hx"<<endl;}
  if((B<C&&C<D)||(C<B&&B<D))
  {
    if(sunuke_dp(C)&&hunuke_dp(D)) {cout<<"Yes"<<endl; return 0;}
    cout<<"No"<<endl; return 0;
  }
  if(sunuke_dp(C)&&hunuke_dp(D))
  {
    for(int i=B;i<=D;i++)
    {
      if(S.at(i-1)=='.'&&S.at(i)=='.'&&S.at(i+1)=='.')
      {
        cout<<"Yes"<<endl; return 0;
      }
    }
  }
  cout<<"No"<<endl; 
    
  return 0;
}