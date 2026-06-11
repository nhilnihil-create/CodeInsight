#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define All(a) a.begin(),a.end()
#define INF 1000000007
const int MOD = 1000000007;
//accumulate(vec.begin(), vec.end(), 0)

int gcd(int x,int y){
  if(x%y==0) return y;
  else return gcd(y,x%y);
}

int main(){
  int a,b,m;
  int money = 0;
  cin >> a >> b >> m;
  vector<int>A(a);
  vector<int>B(b);
  for(int i=0;i<a;i++) cin >> A[i];
  for(int i=0;i<b;i++) cin >> B[i];
  money = *min_element(All(A)) + *min_element(All(B));

  for(int i=0;i<m;i++){
    int x,y,c;
    cin >> x >> y >> c;
    money = min(money,A[x-1]+B[y-1]-c);
  }
  cout<< money <<endl;



}
