#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define repo(i,N) for(int i = 1; i < (N); i++)
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
//#define num 1000000007
#define pi acos(-1.0)
//cout << fixed << setprecision (10);   小数点以下１０桁まで
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'大文字'+=32;    で小文字に
//string s = to_string(int数);
//int n = stoi(string文字列);

int main() {
  int a,b;
  cin >>a>>b;
  
  int ans = 0;
    
  if(a==1) ans+=3;
  if(a==2) ans+=2;
  if(a==3) ans+=1;
  if(b==1) ans+=3;
  if(b==2) ans+=2;
  if(b==3) ans+=1;
  if(a==1 && b==1) ans+=4;
    
  cout << ans*100000 <<endl;
    
}
