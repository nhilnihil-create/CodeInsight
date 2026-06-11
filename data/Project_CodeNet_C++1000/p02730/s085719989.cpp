#include <stdio.h>
#include <iostream>
#include <climits>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <utility>
#include <queue>
 
using namespace std;

#define ll long long
#define ulli  unsigned ll int
#define sl(n) scanf("%lld", &n)
#define sl2(a,b) scanf("%lld%lld", &a,&b)
#define sl3(a,b,c) scanf("%lld%lld%lld", &a,&b,&c)
#define VI  vector<int>
#define Vll  vector<ll>
#define all(v)  v.begin(),v.end()
#define ub(v,x)  upper_bound(all(v),x)

int st(int x,int pos){  return x= x |(1<<pos);}
int  Reset(int x,int pos ){ return x= x &~(1<<pos);}

#define  si(n) scanf("%d", &n)
#define  si2(a,b) scanf("%d%d", &a,&b)
#define  si3(a,b,c) scanf("%d%d%d", &a,&b,&c)
#define  sf(n) scanf("%lf", &n)
#define  pii pair <int, int>
#define  pll pair <ll, ll>
#define  plp pair <int, pll >
#define  pb push_back
#define  mkpr  make_pair
#define  ff   first
#define  ss  second
#define  srt(V)  sort(V.begin(),V.end());
#define  rsrt(V)  sort(V.rbegin(),V.rend());
#define  nl printf("\n");   
#define  PI  2*acos(0.0);
#define  INFP ((ll)1<<62)
#define  INFN (0-(ll)1<<62)
#define  loop(a,b)  for(int g=a;g<=b;g++)
#define  for1(n)  for(int i=0;i<n;i++)
#define  for2(n)  for(int j=0;j<n;j++)
#define  for3(n)  for(int k=0;k<n;k++)
#define  for4(n)  for(int l=0;l<n;l++)
#define  fr(i,a,b) for(int i=a;i<=b;i++)
#define  bug1(a)  cout<<a<<endl;
#define  bug2(a,b)  cout<<a<<" "<<b<<endl;
#define  bug3(a,b,c)  cout<<a<<" "<<b<<" "<<c<<endl;
#define  bug4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

#define  tst(n)  for(int cs=1;cs<=n;cs++)
#define  spc <<" "<<
#define  pys puts("Yes");
#define  pno  puts("No");
#define  bug puts("bug");
#define  pmn puts("-1");
#define  zero puts("0");
#define  limit 200006
#define  md 1000000007
#define  sq(n)  n*n





typedef pair<ll,ll> iPair;


int main()
{
 
               
     /*  freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
*/

       string A;

       cin>>A;
       ll n=A.size();
       bool no=false;

       for(ll i=0;i<n/2;i++)
       {

        if(A[i]!=A[n-i-1])no=true;


       }

       for(ll i=0;i<(n/4);i++)
       {
        //cout<<i<<" "<<(n/2)-i-1<<endl;


        if(A[i]!=A[(n/2)-i-1])no=true;

       }
       ll c=n-1;
       for(ll i=(n/2)+1;i<c;i++)

       {
        //cout<<i<<" "<<c<<endl;

        if(A[i]!=A[c])no=true;
        c--;
       }

       if(no)pno
        else pys

           




    

 

        /**
       *    @author     : Ikbal Hossain
       *    @University  : RUET CSE 15
       *    @CodeForces : iAmrifat
       *    @UVA        : rifat_ikbal
       *    @facebook   : https://www.facebook.com/ikbal.rifat.5
       */
 
      /* ll dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
      /* ll dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
      /* ll dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
      /* ll dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction
 
}
 
 
 
