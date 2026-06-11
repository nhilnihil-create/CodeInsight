#include<bits/stdc++.h>


/* 
*    coder :: ATUL_PANDEY_2608
*        >>> INDIA <<<
*/
using namespace std;

// #define  part ..
#define listi vector<int >
#define listll vector<long long >
#define pii pair<int ,int >
#define pll pair<long long ,long long >
#define heap priority_queue<long long >
#define all(a) a.begin(),a.end()
#define pb(a) push_back(a)
#define mod 998244353
#define maxx 200006
#define ll long long
#define quick   ios_base::sync_with_stdio(NULL),cin.tie(0);
#define rep(i,a,b) for(int i=a;i<b;i++)
long long gcd(long long a, long long b) {
  while (b > 0) {
    long long t = a % b;
    a = b;
    b = t;
  }
  return a;
}
 
// #define test int t;cin>>t;while(t--)
// end of #define 

// define globals ...


long long ni() {
  int c = getchar();
  while (c < '0' || c > '9') c = getchar();
  long long ret = 0.0;
  while (c >= '0' && c <= '9') {
    ret = ret * 10 + c - '0';
    c = getchar();
  }
  return ret;
}





int Main ()
{

 
   ll r,c;
   cin>>r>>c;

   if(r==1 || c==1){
    cout<<1;
    return 0;
   }

   cout<<(r*c+1)/2;
   return 0;


}























// main function..
int main ()
{
  quick;

#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
  freopen ("outt.txt", "w", stdout);
#endif

  Main ();


}
