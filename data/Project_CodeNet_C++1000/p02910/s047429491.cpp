#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pint;

#define INF 99999999
#define rep(i,n) for(int i=0,temp=(int)(n);i<temp;++i) 
#define repi(i,start,end) for(int i=start,temp=(int)(end);i<end;++i)
#define rfor(v,x) for(const auto& x : v) 
#define all(x) (x).begin(),(x).end()
#define SORT(v, n) sort(v, v+n)
#define vsort(v) sort(v.begin(), v.end())
#define vfsort(v,lambda) sort(v.begin(),v.end(),lambda)
#define vint vector<int>
#define vvint vector<vector<int>> 
#define vin(v) rep(i,v.size()) {cin >> v[i];}

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(void){
  string s;cin >> s;
  rep(i,s.length())
    if(i%2==0&&s[i]=='L'||i%2&&s[i]=='R'){
      cout << "No" << endl;
      return 0;
    }
  cout << "Yes" << endl;
}