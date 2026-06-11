#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0;i<n;i++)
#define repm(i,m,n) for(ll i=m;i<n;i++)
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define YesNo(a) (a)?cout<<"Yes"<<endl:cout<<"No"<<endl
#define YESNO(a) (a)?cout<<"YES"<<endl:cout<<"NO"<<endl
#define INF (2e9)
#define PI (acos(-1))
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007

typedef long long ll;

int main(){
  int n; cin >> n;
  string s; cin >> s;

  reverse(all(s));

  int disastar_count = 0;
  int disastar_point = 0;
  bool disastar = false;
  rep(i,n){
    if(!disastar && s[i] == 'R'){
      disastar = true;
      disastar_point = i;
    }
    if(disastar && s[i] == 'W'){
      disastar_count++;
    }
  }

  int d = disastar_point+disastar_count;
  repm(i,disastar_point,d){
    if(s[i] == 'W') disastar_count--;
  }

  cout << disastar_count << endl;
}