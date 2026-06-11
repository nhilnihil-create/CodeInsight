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

int n;
vector<int> adj[100];
string col = "RGB";

char getCur(char frst , char sec){
  for (int i = 0; i < 3; ++i)
    if(frst != col[i] && sec != col[i])
      return col[i];
}

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  string s;
  cin >> n;
  cin >> s;
  int len = SZ(s);
  for (int i = 0; i < len; ++i)
    adj[s[i]].push_back(i);

  ll cnt = 0;
  for (int i = 0; i < n; ++i)
  {
    for (int j = i + 1; j < n; ++j){
      if(s[i] == s[j])
        continue;
      char curChar = getCur(s[i], s[j]);
      int sz = SZ(adj[curChar]);
      int idx = lower_bound(adj[curChar].begin(), adj[curChar].end(), j + (j - i)) - adj[curChar].begin();
      cnt += (sz - (lower_bound(adj[curChar].begin(), adj[curChar].end(), j + 1) - adj[curChar].begin()));
      if(idx < sz && adj[curChar][idx] == j + (j - i))
        cnt--;
    }
  }
  cout << cnt << "\n";

  return 0;
}
