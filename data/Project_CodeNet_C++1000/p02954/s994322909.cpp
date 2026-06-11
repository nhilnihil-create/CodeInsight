#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
//#define P pair<ll, ll>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;

struct info {
  int group;
  int pos;
  int left = 0;
  int right = 0;
};

int
main()
{
 
  string s; cin >> s;
  int N = s.size();
  vector<int> arr(0);
  rep(i, 0, N){
    if(s[i] == 'R') arr.push_back(1);
    else arr.push_back(0);
  }

  int group = 0;
  int pos = 0;
  bool leftflag = false;
  vector<pair<int, int>> grouplen(N);
  vector<info> infos(N);
  rep(i, 0, N){
    if(arr[i] == 1){
      if(leftflag == true){
        group += 1;
        pos = 0;
        leftflag = false;
      }
      infos[i].pos = pos++; 
      infos[i].group = group;
      grouplen[group].first += 1;
    } else if (arr[i] == 0 && leftflag == true){
      infos[i].group = group;
      infos[i].left += infos[i - 1].left + 1;
      grouplen[group].second += 1;
    } else {
      grouplen[group].first += 1;
      infos[i].group = group;
      leftflag = true;
    }
  }
  vector<int> ans(N);

  int sum = 0;
  for(auto x: grouplen){
    int all = x.first + x.second;
    rep(i, 0, all){
      int si = grouplen[infos[i + sum].group].first - 2;
      if(arr[i + sum] == 1){
        int move = 100000 - (si - infos[i + sum].pos);
        if(move % 2 == 0) ans[sum + si] += 1;
        else ans[sum + si + 1] += 1;

      } else {
        si += 1;
        int move = 100000 - infos[i + sum].left;
        if(move % 2 == 0) ans[sum + si] += 1;
        else ans[sum + si - 1] += 1;
      }
    }
    sum += x.first + x.second;
  }
   
  for(auto x: ans){
    cout << x << " ";
  }
  cout << endl;

}