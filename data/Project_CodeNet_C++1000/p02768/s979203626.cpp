#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb push_back;
#define sp " ";
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<
    v.at(i)<<endl;
}
int modpow(long long int a, long long int n, long long int p) {
  if (n == 0) return 1; // 0乗にも対応する場合
  if (n == 1) return a % p;//n=1ならaを返す
  if (n % 2 == 1) return (a * modpow(a, n - 1, p)) % p;//nが奇数なら偶数にする
  long long t = modpow(a, n / 2, p);//nが偶数なら半分にする
  return (t * t) % p;
}
int modchoose(lli n,lli k,lli m){
  lli ans=1;
  rep(i,k){
    ans=(ans*(n-i))%m;
    ans=(ans*modpow(i+1,m-2,m))%m;
  }
  return ans;
}

int main(){
    lli ele=1000000007;
    lli all,a,b,n;
    cin>>n>>a>>b;
    all=modpow(2,n,ele)-1;
    a=modchoose(n,a,ele);
    b=modchoose(n,b,ele);
    all=all-a-b;
    while(all<0){
      all+=ele;
    }
    cout<<all;

}