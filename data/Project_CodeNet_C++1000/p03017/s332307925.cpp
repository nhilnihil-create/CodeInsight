#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, A, B, C, D;
  string S;
  cin>>N>>A>>B>>C>>D;
  A--;
  B--;
  C--;
  D--;
  cin>>S;
  bool ans;
  while(true){
    if(C<D){
      if(B<D && B+2<=D && S[B+2]=='.' && B+2!=A){
        B += 2;
      }
      else if(B<D && B+1<=D && S[B+1]=='.' && B+1!=A){
        B += 1;
      }
      else if(A<C && A+1<=C && S[A+1]=='.' && A+1!=B){
        A += 1;
      }
      else if(A<C && A+2<=C && S[A+2]=='.' && A+2!=B){
        A += 2;
      }
      else if(A==C && B==D){
        ans = true;
        break;
      }
      else {
        ans = false;
        break;
      }
    }
    else{
      if(A<C && A+2<=C && S[A+2]=='.' && A+2!=B){
        A += 2;
      }
      else if(A<C && A+1<=C && S[A+1]=='.' && A+1!=B){
        A += 1;
      }
      else if(B<D && B+1<=D && S[B+1]=='.' && B+1!=A){
        B += 1;
      }
      else if(B<D && B+2<=D && S[B+2]=='.' && B+2!=A){
        B += 2;
      }
      else if(A==C && B==D){
        ans = true;
        break;
      }
      else {
        ans = false;
        break;
      }
    }
  }
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

