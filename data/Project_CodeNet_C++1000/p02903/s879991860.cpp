#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 1000000009
using P = pair<int,int>;

int main() {
  int h,w,a,b;
  cin >> h >> w >> a >> b;
  bool flag = false;
  string standard = "";
  rep(i,h){
    if(i<b){
      rep(j,w){
        if(j<a){
          cout << '0';
        }
        else{
          cout << '1';
        }
      }
      cout << endl;
    }
    else{
      rep(j,w){
        if(j<a){
          cout << '1';
        }
        else{
          cout << '0';
        }
      }
      cout << endl;
    }
  } 
}
