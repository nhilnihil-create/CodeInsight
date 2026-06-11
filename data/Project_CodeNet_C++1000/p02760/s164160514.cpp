#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int bingo[3][3];
bool judge[3][3];
int main()
{
  rep(i,3)
  {
    rep(j,3)
    {
      cin >> bingo[i][j];
    }
  }
  int n;cin >> n;
  rep(i,n)
  {
    int temp;cin >> temp;
    rep(i, 3)
    {
      rep(j, 3)
      {
        if(temp==bingo[i][j])
        {
          judge[i][j] = true;
        }
      }
    }
  }
  
  rep(i,3)
  {
    bool flag = true;
    rep(j,3)
    {
      if(!judge[i][j])
      {
        flag = false;
        break;
      }
    }
    if(flag)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  rep(i, 3)
  {
    bool flag = true;
    rep(j, 3)
    {
      if (!judge[j][i])
      {
        flag = false;
        break;
      }
    }
    if (flag)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  bool flag = true;
  rep(i,3)
  {
    if(!judge[i][i])
    {
      flag = false;
      break;
    }
  }
  if(flag)
  {
    cout << "Yes" << endl;
    return 0;
  }
  flag = true;
  rep(i,3)
  {
    if(!judge[i][2-i])
    {
      flag = false;
      break;
    }
  }
  if (flag)
  {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}