#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
const int N = 1e6 + 10, OO = 0x3f3f3f3f, mod = 1e9 + 7;

#define PI acos(-1)
#define clr(arr, val) memset(arr, val, sizeof(arr))
#define loop(i, n) for (int i = 0; i < int(n); i++)
#define rloop(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define xloop(i, a, b) for (int i = int(a); i <= int(b); i++)
#define ALL(v) ((v).begin()), ((v).end())
#define SZ(v) ((int)((v).size()))
int dx[] = {1, 0, -1, 0}; // {down , right , up , left}
int dy[] = {0, 1, 0, -1}; //4 Direction
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
//int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; //8 direction
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1}; //Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

//-- "كلٌّ من يسعى لابد يصل .. كلٌّ من يسعى مضمون له الوصول" --//

int k;
vector<ll> cur;
set<ll> nums;

void solve(int len, ll rkm)
{
  nums.insert(rkm);
  if(SZ(nums) > k)
    nums.erase(*nums.rbegin());
  if(len == 10)
    return;
  for (int i = -1; i <= 1; ++i){
    ll value = cur.back() + i;
    if(value >= 0 && value < 10){
      cur.push_back(value);
      solve(len + 1, (rkm * 10 + value));
      cur.pop_back();
    }
  }
}

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  scanf("%d", &k);
  for(int i = 1 ; i < 10 ; ++i){
    cur.push_back(i);
    solve(0, i);
    cur.pop_back();
  }
  printf("%lld\n", *nums.rbegin());

  return 0;
}
