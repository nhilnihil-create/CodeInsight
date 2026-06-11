/*
Author :Ashraful Mehmet Fuad
date :23 Jan 2020
TODO --list
Hey What's up Mr . Spy ?
*/
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
#include<bits/stdc++.h>
using namespace std;
int tc,cs=1;
typedef long long ll;
const int N=10000+5;
 

class Game{
  private:
  int n,k;
  
  public:
  Game(int n,int k)
  {
    this->n=n;
    this->k=k;
  }

  int solve()
  {
    if(1==this->k)return 0;

    return this->n-this->k;
  }
};

 
int main()
{
  fastio
  // input
  // output
  int n,k;
  cin>>n>>k;
  Game *obj;

  obj=new Game(n,k);

  cout<<obj->solve()<<endl;

  
  
  return 0;
}// end func