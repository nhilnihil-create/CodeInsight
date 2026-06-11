//AUTHOR: RAVAN_2070
//PUNE INSTITUTE OF COMPUTER TECHNOLOGY
/*
    I LOVE CLARICE STARLING

     ♥LOVE♥        ♥LOVE♥
  ♥LOVE♥♥LOVE♥  ♥LOVE♥♥LOVE♥
♥LOVE♥♥LOVE♥♥LOVE♥♥LOVE♥♥LOVE♥
   ♥LOVE♥♥LOVE♥♥LOVE♥♥LOVE♥
      ♥LOVE♥♥LOVE♥♥LOVE♥
         ♥LOVE♥♥LOVE♥
            ♥LOVE♥
               ♥


    EXPLAINATION BELOW->
    Greedy
    1)WE mark the first possible days in each stage,We also mark the last possible days for each days
     ex-16 4 3
        ooxxoxoxxxoxoxxo
    first possible ex-1 5 11 16
    last possible ex-2 7 11 16
    all possible values for stages::
    stage (1) 1,2
    stage (2) 5,6,7
    stage (3) 11
    stage (4) 16
    2)Find the earliest and latest day of the i-th working day. If for some i they are the same, this is a day bound to work.
    since if they are same for earliest and lastest case it implies it is also same for all middle cases as well 
      
*/
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<pair<ll,ll>> vii;
typedef pair<ll,ll> pii;
typedef map<ll,ll> mii;
#define MOD7 1000000007
#define MOD9 1000000009
#define pi 3.1415926535
#define Test_cases ll TC;cin>>TC;while(TC--)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define sp(x) fixed<<setprecision(x)
#define sz(x) (ll)(x.size())
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
void solve()
{
  int n,k,c,K,i,x=0;cin>>n>>k>>c;K=k;
  string s;cin>>s;
  int early[n],late[n];
  fo(i,0,n)early[i]=late[i]=0;
  
  for(i=n-1;i>=0;i--)
  {
      if(s[i]=='o')late[i]=k--,i-=c;
      if(k==0)break;
  }
  
  for(i=0;i<n;i++)
  {
     if(s[i]=='o')early[i]=++x,i+=c;
     if(x==K+1)break; 
  }
  
  fo(i,0,n)
  if(late[i]!=0&&late[i]==early[i]&&s[i]=='o')cout<<i+1<<"\n";
  
}
int main()
{
   fastio
   solve();
  return 0;
}
//map<ll,ll,greater<int>> to sort in descending order ,in iterator declaration no greater<int>
//if you want to apply lowerbound on set use s.lower_bound(key),not the one used for vector
/* TIPS FOR DEBUGGING
 * Check if values are not overflowing (use long long where required)
 * Check if ranges are inclusive or not.
 * Check properly if greedy will work or not before using it.
 * Check EDGE CASES!! Seriously, even in 2B, saving 8 points by being
 * 2 minutes faster will bite you in the ass if you don't make sure
 * it works on edge cases.
 * Keep adding to this list.
*/
//AUTHOR: RAVAN_2070
//PUNE INSTITUTE OF COMPUTER TECHNOLOGY
/*
    I LOVE CLARICE STARLING

     ♥LOVE♥        ♥LOVE♥
  ♥LOVE♥♥LOVE♥  ♥LOVE♥♥LOVE♥
♥LOVE♥♥LOVE♥♥LOVE♥♥LOVE♥♥LOVE♥
   ♥LOVE♥♥LOVE♥♥LOVE♥♥LOVE♥
      ♥LOVE♥♥LOVE♥♥LOVE♥
         ♥LOVE♥♥LOVE♥
            ♥LOVE♥
               ♥


    EXPLAINATION BELOW->
    1)From every lunlun number we can generate new 3 lunlun numbers ==>10x + (x mod 10) − 1,10x + (x mod 10),10x + (x mod 10) + 1
    But some lunlun numbers get repeated for example
    9=>98,99,100
    10=>99,100,101
    so rules come out like given in editorial
    2)We use Queue since it helps in maintaining the order
    3)We know the first 9 lunlun numbers
      
*/
/*
void solve()
{
  int k;cin>>k;
  queue<ll>Q;
  ll i,element;
  foe(i,1,9)Q.push(i);
  while(k--)
  {
      element=Q.front();Q.pop();
      if(element%10!=0)Q.push(10*element+element%10-1);
      Q.push(10*element+element%10);
      if(element%10!=9)Q.push(10*element+element%10+1);
  }
  cout<<element<<"\n";
  
  
}
*/
