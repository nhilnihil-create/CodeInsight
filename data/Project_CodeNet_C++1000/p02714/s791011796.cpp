#include<bits/stdc++.h>
//One implementation to rule them all?
#define db              double
#define ll              long long int
#define ld                long long double
//#define int           long long int
#define ull             unsigned long long
#define fi              first
#define se              second
#define rep(i,a,n)      for(int i=a;i<n;i++)
#define repr(i,n,b)     for(int i=n;i>=b;i--)
#define endl            '\n'
#define mem(a,b)        memset(a, b, sizeof a)
#define mkp             make_pair
#define pb              push_back
#define max3(a,b,c)     max(a,max(b,c))
#define min3(a,b,c)     min(a,min(b,c))
#define w(t)            int t; cin>>t; while(t--)
#define all(a)          a.begin(), a.end()
#define sz(a)           int((a).size())
#define debug(x) (cerr << #x << " = " << x << endl;)
//Bitwise 
#define isOn(S, j) (S & (1<<j))
#define setBit(S, j) (S |= (1<<j))
#define clearBit(S, j) (S &= ~(1<<j))
#define toggleBit(S, j) (S ^= (1<<j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1<<n)-1)
#define turnOffLastBit(S) ((S) & (S-1))
#define turnOnLastZero(S) ((S) | (S+1))
//Can use tuples in C++17
using namespace std;
typedef vector < int > vii;
typedef vector < ll > vll;
typedef vector < vii > vvi;
typedef pair < int,int > pii;
template <class T> using min_heap = priority_queue<T,vector<T>,greater<T> >;
template <class T> using max_heap = priority_queue<T>;
const db PI = 2*acos(0.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;
db eps       =          0.000001;
ll mod       =          (1e9+7);   //998244353
void print(vector <int> &arr){
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    
    cout<<endl;
}
void printll(vector <ll> &arr){
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    
    cout<<endl;
}

ll ncr(ll n, ll r)
{
    r=min(r,n-r);
    ll A[r],i,j,B[r];
    iota(A,A+r,n-r+1);  
    iota(B,B+r,1);     

    ll g;
    for(i=0;i<r;i++)
    for(j=0;j<r;j++)
    {
        if(B[i]==1)
            break;
        g=__gcd(B[i], A[j] );
        A[j]/=g;
        B[i]/=g;
    }
    ll ans=1;
    for(i=0;i<r;i++)
        ans=(ans*A[i]%mod);
    return ans;
}
const int SIZE=1e5+5;
bool judgePermutation(int a[], int n){
    static int used[SIZE+1];
    for(int i = 1; i <= n; i++) used[i] = 0;
    for(int i = 0; i < n; i++) used[a[i]] = 1;
    for(int i = 1; i <= n; i++) {
        if(!used[i]) return 0;
    }
    return 1;
}
ll v[3];
 
int idx(char x)
{
  if(x == 'R')
    return 0;
  else if(x == 'G')
    return 1;
  else
    return 2;
}
int main(){ 
//CONDITION && cout << "YES" || cout << "NO"; cout << '\n';
//////////////////////////////////////////////////////////////////////
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.tie(NULL);
//For fast IO
///////////////////////////////////////////////////////////////////// 
//  std::cout.unsetf ( std::ios::floatfield );  // floatfield not set
//  std::cout.precision(10);
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
	int n;
	  string s;
	  cin >> n >> s;
	  for(int i = 0; i < n ; i++)
	  {
	    v[idx(s[i])]++;
	  }
	 
	  ll ans = v[0] * v[1] * v[2];
	  for(int i = 0; i < n; i++)
	  {
	    for(int j = i + 1; j < n; j++)
	    {
	      int k = 2*j - i;
	      if(k < n && s[i] != s[j] && s[j] != s[k] && s[i] != s[k])
	        ans--;
	    }
	  }
	  cout << ans << endl;
	return 0;
}