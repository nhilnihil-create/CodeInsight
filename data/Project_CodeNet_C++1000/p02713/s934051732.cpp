#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000000 //10^12:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素

int gcd(int a, int b){
    int r, tmp;

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
    return b;
}

int main(){
    int K;
    cin>>K;
    ll ans=0;
    for(int i=1;i<=K;i++){
        for(int j=1;j<=K;j++){
            int temp=gcd(i,j);
            for(int k=1;k<=K;k++){
                ans+=gcd(temp,k);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
