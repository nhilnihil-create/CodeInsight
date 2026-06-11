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
    Read Editorial First
    for example given in it M=5;
    1)Pairs are seen in first round no multiple fields are assigned same integer
    2)now consider from round
    1 - 5 (diff - 4)
    8 -9  (diff- 1)
    so even though the case of 8-9 in which 1 occurs (1-2)will have different pair than 1-5 since distance of both original pairs 1-5 and 8-9 are different

*/
//E-Rotation Matching
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
   int N,M;cin>>N>>M;
   int l1,r1,l2,r2;
   //part1
   l1=1;
   if(M&1)r1=M;
   else r1=M+1;
   
   l2=r1+1;
   while(l1!=r1){cout<<l1<<" "<<r1<<"\n";l1++;r1--;}
   //part2;
   r2=2*M+1;
   while(l2<r2){cout<<l2<<" "<<r2<<"\n";l2++;r2--;}
   
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
/*   EXPLAINATION BELOW->
     The bank pays an annual interest rate of 1 % compounded annually. 
     P+=(P*1)/100;
*/
/*void solve()
{
   ll X,P=100;cin>>X;
   int cnt=0;
   while(P<X)
   {
       P+=(P/100);
       cnt++;
   }
   cout<<cnt<<"\n";
}*/
/*
 *  EXPLAINATION BELOW->
    Brute force Complete Search + Backtracking
    Read Editorial
    https://cp-algorithms.com/combinatorics/stars_and_bars.html
    https://www.youtube.com/watch?v=qvqPZkPURCo
    https://codeforces.com/blog/entry/76792?#comment-614251

 ll ans;
vector<int>a,b,c,d;
int n,m,q;
void recursion(vector<int> A)
{
    int i;
   if(sz(A)==n+1)
   {
       ll score=0;
       fo(i,0,q)
       {
           if(A[b[i]]-A[a[i]]==c[i])score+=d[i];
       }
       ans=max(ans,score);
   }
   else
   {
       int last_entered=A.back();
       fo(i,last_entered,m+1)
       {
           A.pb(i);
           recursion(A);
           A.pop_back();
       }
   }
 
}
void solve()
{
   cin>>n>>m>>q;
   int i;
   a=b=c=d=vector<int>(q,0);
   fo(i,0,q)
   cin>>a[i]>>b[i]>>c[i]>>d[i];
   
   recursion(vector<int>(1,1));
   cout<<ans<<"\n";
   
}*/
/*
EXPLAINATION BELOW->
    It can be seen easily thatf(x+B) =f(x) by actually assigning.  So, we consider only0≤x≤B−1.
void solve()
{
    ld A,B,N;cin>>A>>B>>N;
    if(N>=B)
    cout<<floor(A*(B-1)/B)<<"\n";
    else
    cout<<floor(A*(N)/B)<<"\n";
}
*/