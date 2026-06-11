#include "bits/stdc++.h"

using namespace std;


// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //

#define int                                       long long
#define lop(i,s,e)                                for(int i=s;i<(int)e;i++)
#define rlop(i,e,s)                               for(int i=e;i>=s;i--)
#define prvec(v)                                  lop(R15,0,v.size())cout << v[R15] <<" "; cout << endl;
#define prarr(arr,s1,e1)                          lop(R15,s1,e1)cout << arr[R15] << " "; cout << endl;

#define endl                                      '\n'
#define ff                                        first
#define ss                                        second
#define pii                                       pair<int,int>

#define pb                                        push_back
#define vi                                        vector<int> 
#define vpii                                      vector< pii >

#define all(v)                                    v.begin(),v.end()
#define sZ(re)                                    (int)re.size()
#define mset(a,f)                                 memset(a,f,sizeof(a))
#define M                                         1000000007
#define Think_Twice_Code_Once                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)


bool J27 = 1;
#define bug(...)                                  __f (#__VA_ARGS__, __VA_ARGS__)
#define rtn                                       if(!J27)return;
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { rtn cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{     rtn 
     const char* comma = strchr (names + 1, ',');
     cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //

inline void INP();
const int N = 3e6 + 7;
const long long INF = LLONG_MAX;
const int inf = INT_MAX;

int n, Q;
int arr[N+2];

void solve()
{
      cin >> n;
      lop(i,0,n) cin >> arr[i];

      vi vec(3, 0);

      int ans = 1;
      lop(i,0,n)
      {	
      	int val = 0, f = 0;
      	lop(j,0,3)
      	{
      		if( vec[j] == arr[i] )
      		{
      			if(!f) vec[j]++, f = 1;
      			val++;
      		}
      	}
      	ans *= val;
      	ans %= M;
      }

      cout << ans << endl;

}


int32_t main()
{

      J27 = 1;
      Think_Twice_Code_Once;
//      INP(); 
      int t = 1;
      //cin >> t;
      while(t--) solve();


}











inline void INP()
{
      #ifndef ONLINE_JUDGE
          freopen("input.txt",  "r",  stdin);
          freopen("output.txt", "w", stdout);
      #endif
}


// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //




