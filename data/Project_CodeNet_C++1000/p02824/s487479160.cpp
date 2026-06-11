/*やったぜ。　投稿者：変態糞土方 (8月16日（水）07時14分22秒)

昨日の8月15日にいつもの浮浪者のおっさん（60歳）と先日メールくれた汚れ好きの土方のにいちゃん

（45歳）とわし（53歳）の3人で県北にある川の土手の下で盛りあったぜ。

今日は明日が休みなんでコンビニで酒とつまみを買ってから滅多に人が来ない所なんで、

そこでしこたま酒を飲んでからやりはじめたんや。

3人でちんぽ舐めあいながら地下足袋だけになり持って来たいちぢく浣腸を3本ずつ入れあった。

しばらくしたら、けつの穴がひくひくして来るし、糞が出口を求めて腹の中でぐるぐるしている。

浮浪者のおっさんにけつの穴をなめさせながら、兄ちゃんのけつの穴を舐めてたら、

先に兄ちゃんがわしの口に糞をドバーっと出して来た。

それと同時におっさんもわしも糞を出したんや。もう顔中、糞まみれや、

3人で出した糞を手で掬いながらお互いの体にぬりあったり、

糞まみれのちんぽを舐めあって小便で浣腸したりした。ああ～～たまらねえぜ。

しばらくやりまくってから又浣腸をしあうともう気が狂う程気持ちええんじゃ。

浮浪者のおっさんのけつの穴にわしのちんぽを突うずるっ込んでやると

けつの穴が糞と小便でずるずるして気持ちが良い。

にいちゃんもおっさんの口にちんぽ突っ込んで腰をつかって居る。

糞まみれのおっさんのちんぽを掻きながら、思い切り射精したんや。

それからは、もうめちゃくちゃにおっさんと兄ちゃんの糞ちんぽを舐めあい、

糞を塗りあい、二回も男汁を出した。もう一度やりたいぜ。

やはり大勢で糞まみれになると最高やで。こんな、変態親父と糞あそびしないか。

ああ～～早く糞まみれになろうぜ。

岡山の県北であえる奴なら最高や。わしは163*90*53,おっさんは165*75*60、や

糞まみれでやりたいやつ、至急、メールくれや。

土方姿のまま浣腸して、糞だらけでやろうや。*/
#include "bits/stdc++.h"
#include <numeric>
#define rep(i,n) for(ll i = 0; i < n; i++)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define llMAX numeric_limits<long long>::max()
#define intMAX numeric_limits<int>::max()
#define llMIN numeric_limits<long long>::min()
#define intMIN numeric_limits<int>::min()
#define d_5 100000
#define d9_7 1000000007
#define vll vector<vector<long long>>
#define vl vector<long long>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pf push_front
#define ld long double
#define Sort(a) sort(a.begin(),a.end())
#define reSort(a) sort(a.rbegin(), a.rend())
ll digitpower(ll a,ll b){//aのb乗を計算
  if(b==1){
    return a;
  }else if(b==0){
    return 1;
  }
  if(b%2==1){
    ll tmp = digitpower(a,(b-1)/2);
    tmp%=d9_7;
    tmp*=tmp;
    tmp%=d9_7;
    tmp*=a;
    return (tmp)%d9_7;
  }else{
    ll tmp = digitpower(a,(b)/2);
    tmp%=d9_7;
    tmp*=tmp;
    tmp%=d9_7;
    return (tmp)%d9_7;
  }
}
//階乗
vl facs(1000000,-1);
ll Factrial(ll num){
  if(facs[num]!=-1){
    return facs[num];
  }
  if(num==1||num<=0){
    return 1;
  }else if(num<0){
    printf("ERROR_minus\n");
    return 0;
  }else{
    facs[num]=(num*Factrial(num-1))%d9_7;
    return facs[num];
  }
}
long long modinv(long long a, long long m) {//modの逆元
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}
ll linercomb(ll n,ll k, ll mod){//n,kの線形時間で求める
  ll ans=Factrial(n);
  ans*=modinv(Factrial(k),mod);
  ans%=d9_7;
  ll k1=Factrial(k);
  k1%=mod;
  ans*=modinv(k1,mod);
  ans%=mod;
  return ans;
}
struct datas{
  ll x;
  ll l;

};
bool cmp(const datas &a, const datas &b)
{
    return a.x < b.x;
}
int main(void){
  ll n,m,v,p;
  cin>>n>>m>>v>>p;
  vl a;
  a=vl(n);
  rep(i,n){
    cin>>a[i];
  }
  reSort(a);
  ll l=p-1,r=n-1;
  ll mid=(l+r)/2;
  while(l!=r){
    mid=(l+r)/2;
    if(r-l==1){
      mid++;
    }
    //cout<<l <<" "<<r<<endl;
    if(mid==p-1){
      break;
    }
    if(a[p-1]>m+a[mid]){
      r=mid-1;
      continue;
    }
    ll num=m*v;
    num-=m;
    num-=m*(n-mid-1);
    num-=m*(p-1);
    for(ll now=p-1;now<mid;now++){
      num-=max(min(m+a[mid]-a[now],m),(ll)0);
    }
    if(num<=0){
      l=mid;
      continue;
    }else{
      r=mid-1;
      continue;
    }

  }
  cout<<l+1<<endl;
  return 0;
}
