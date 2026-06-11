#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) max((a),-(a))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define INF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  while(1){
    int n;
    cin >> n;
    if(n==0) return 0;
    string s;
    int ans=0;
    bool yuka=true,l=false,r=false;
    for(int i=0;i<n;i++){
      cin >> s;
      if(s=="lu"){
        l=true;
        if(yuka&l&r){
          yuka=false;
          ans++;
        }
      }else if(s=="ru"){
        r=true;
        if(yuka&l&r){
          yuka=false;
          ans++;
        }
      }else if(s=="ld"){
        l=false;
        if(!yuka&!l&!r){
          yuka=true;
          ans++;
        }
      }else{
        r=false;
        if(!yuka&!l&!r){
          yuka=true;
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}

