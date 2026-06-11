#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 3000;



int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  ll n;
  int a, b;
  char c;
  cin >> n >> a >> c >> b;

  a = a*100+b;
  n = n*a;

  string ans = to_string(n);

    n = ans.size();
    if(n < 3)cout << "0" << endl;
    else{
        forn(i, 0, n-2){
            cout << ans[i];
        }cout << endl;
    }


	
}



