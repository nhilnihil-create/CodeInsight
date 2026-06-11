#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000 //10^9:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素

ll lcm(ll A, ll B)
{

    ll a, b, r, tmp;
    a=A;
    b=B;
 
  /* 自然数 a > b を確認・入替 */
  if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }

  /* ユークリッドの互除法 */
  r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
  return A*B/b;
}

int main() {
    int N,M;
    cin>>N>>M;
    vector<int> a(N);
    int A;
    bool b=false;
    int cc;
    rep(i,N){ 
        cin>>A;
        int c=0;
        while(A%2==0){
            c++;
            A=A/2;
        }
        a[i]=A;
        if(i==0) cc=c;
        else if(cc!=c){
            cout<<"0"<<endl;
            return 0;
        }
    }
    ll l=a[0];
    for(int i=1;i<N;i++) l=lcm(l,a[i]);
    rep(i,cc-1) M/=2;
    int ans=M/l;
    ans=ans/2+ans%2;
    cout<<ans<<endl;
    return 0;
}