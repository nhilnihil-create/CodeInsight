#include "bits/stdc++.h"
using namespace std;
typedef  long long ll ;
typedef vector<int> ve ;
typedef pair <int , int> pr ;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MAX INT_MAX
#define MIN (-1 * INT_MAX)
#define rep(i,a,b) for(ll i = a ; i< b ; ++i)
#define repp(i,a,b) for(i = a ; i< b ; ++i)
#define reppp(i,a) for( ll i = a ; i >= 0 ; --i)
#define loop(i , arr)  for(auto i : arr)
#define endl '\n'
ve    vec  , vec2  , vec3  , vec4 , v , p;
ll t , n , k , m , sum , cnt;
map<int,vector<int>> graph ;
vector<ve> sv ;
vector<bool>visited ;
priority_queue<ll> pq ;
map< ll , ll> mp ,  mpp ,mpc ;
bool sortBylength(pair <string , int> &a,pair <string , int>  &b)
{
    return a.first.length() > b.first.length() ;

}
ll power(ll x, unsigned long long int y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}
const int mod = 1e9+7 ;
char ch[100001];
const int sss = 1e6+1 ;
const int sss2 = 1e5+2 ;
int arrr[sss2] = {0} ;
vector <int> alls(6) ;
vector<int>pa ;
map<int , int> mps , mps2r ;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   cin >> n >> k ;
   vec.resize(n) ;
   cnt = 0 ;
   rep(i , 0 , n ) cin >> vec[i] ;
   sort(vec.begin() , vec.end() , greater<int>()) ;
   rep(i , 0 , n){
       if(vec[i] < k ) break;
       cnt++ ;
   }
   cout <<cnt <<endl ;

}