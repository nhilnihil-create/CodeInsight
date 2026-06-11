#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
void tostr(ll x,string& res){while(x)res+=('0'+(x%10)),x/=10; reverse(ALL(res)); return;}
template<class T> inline bool chmax(T& a,T b){ if(a<b){a=b;return 1;}return 0; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){a=b;return 1;}return 0; }
//end

bool nCr(int n,int k){return (n&k)==k;}
bool calc(string s){
   bool f=0; int n=s.size();
   rep(i,0,n)if(s[i]=='1')f^=nCr(n-1,i);
   return f;
}

int main(){
   int n; scanf("%d",&n);
   string s; cin>>s;
   for(auto& c:s)c--;
   string t=s; for(auto& c:t)if(c=='2')c='0';
   if(calc(t))puts("1");
   else{
      for(auto& c:s){
         if(c=='1'){puts("0"); return 0;}
         if(c=='2')c='1';
      }
      if(calc(s))puts("2"); else puts("0");
   }
   return 0;
}