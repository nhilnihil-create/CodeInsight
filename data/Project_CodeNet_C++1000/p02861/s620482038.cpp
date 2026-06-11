#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;


//      DEEP

using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(v) v.begin(),v.end()
#define pb push_back
#define endl '\n'
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pll;
typedef set<int> si;


/*
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
*/
/*
typedef tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
*/

const ll mod = 1e9 + 7;
const ll modl=998244353;
const double pie=3.1415926535;
                                                    //power
ull power(ull x,ull y){
   if(y==0) return 1;
   else{
     if(y%2==0) return power(x*x,y/2);
     else return x*power(x*x,(y-1)/2);
   }
}

                        //                    Modular Exponentiation

ll mod_power(ll x, ll y, ll m)
{
    ll r = 1;     // Initialize result

    x = x % m; // Update x if it is more than or equal to m

    if (x == 0) return 0; // In case x is divisible by m;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            r = (r*x) % m;

        // y must be even now
        y = y/2;
        x = (x*x) % m;
    }
    return r;
}

                                                      //GCD
ll gcd(ll x,ll y){
   if(y==0)return x;
   return gcd(y,x%y);
}
                                              // SIEVE

/*
bool isPrime[100001];
void sieve(int N) {

        for(int i = 0; i <= N;++i) {
            isPrime[i]=true;
        }
        isPrime[0]=false;
        isPrime[1]=false;

        for(int i = 2; i * i <= N; ++i) {
             if(isPrime[i] == true) {
                 for(int j = i * i; j <= N ;j += i)
                     isPrime[j] = false;
            }
        }
    }
*/


 vector<pair<double,double> >point;
 vector<bool>visited;
 double ans=0;
 int n;
 void dfs(int x,vector<bool>visit,double sum){
  visit[x]=true;
  if(count(all(visit),false)==1){
    ans+=sum;
  }else{
  for(int i=1;i<=n;i++){
     if(!visit[i]){
       double c=sum;
       c+=sqrt((point[i].first - point[x].first)*(point[i].first - point[x].first) + (point[i].second - point[x].second)*(point[i].second - point[x].second));
       dfs(i,visit,c);
     }
  }
}

 }
int main(){
    boost;
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--){
      
      cin>>n;
      point=vector<pair<double,double> >(n+1);
      for(int i=1;i<=n;i++)cin>>point[i].first>>point[i].second;
      visited=vector<bool>(n+1,false);
  
      for(int i=1;i<=n;i++){
        dfs(i,visited,0.0);
      }
      int p=1;
      for(int i=1;i<=n;i++)p*=i;
      ans/=p;

      printf("%0.10f\n",ans);
    }
}










