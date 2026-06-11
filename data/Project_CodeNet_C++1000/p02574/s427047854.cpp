#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
const int N = 1e6 + 10, OO = 0x3f3f3f3f, mod = 100000007;

#define PI acos(-1)
#define clr(arr, val) memset(arr, val, sizeof(arr))
#define loop(i, n) for (int i = 0; i < int(n); i++)
#define rloop(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define xloop(i, a, b) for (int i = int(a); i <= int(b); i++)
#define ALL(v) ((v).begin()), ((v).end())
#define SZ(v) ((int)((v).size()))
#define sc1(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1}; //4 Direction
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
//int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; //8 direction
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1}; //Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

//-- "كلٌّ من يسعى لابد يصل .. كلٌّ من يسعى مضمون له الوصول" --//

int n, a[N] , cnt[N] , vis[N];

int gcd(int a, int b){
  if(b == 0)
    return a;
  return gcd(b, a % b);
}

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  int GCD = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i){
    scanf("%d", a + i);
    cnt[a[i]]++;
    GCD = gcd(GCD, a[i]);
  }

  bool tmam = 1;
  int cntMultiple = 0;
  //for every Prime -- multiple of prime -- cnt of each multiple
  for (int i = 2; i < N; ++i){ // for loop on primes
    cntMultiple = 0;
    if(vis[i] == 0)
    {
      for (int j = i; j < N; j += i){ // for loop for multiples of primes
        vis[j] = 1; // 2 4 6 8 10 ....
        cntMultiple += cnt[j];
      }
      if(cntMultiple > 1)
        tmam = 0;
    }
    if(!tmam)
      break;
  }

  if(tmam) // pairwise co-prime
    cout << "pairwise coprime\n";
  else if(GCD == 1 && !tmam)
    cout << "setwise coprime\n";
  else
    cout << "not coprime\n";

  return 0;
}
