#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
#define SORTD(s) sort((s).rbegin(),(s).rend())

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
	ll a,b,c,d,sum;
  
  	cin>>a>>b>>c>>d;
  
  	sum +=b/c-(a-1)/c;//b以下ｃの約数の数を取って、a以下のcの約数を引く
  	sum +=b/d-(a-1)/d;//c以下の
  	int e=gcd(c,d);//最大公約数
  	sum-=b/(c*d/e)-(a-1)/(c*d/e);//最大公約数は2重に足されてるから片方引く//a以下のやつは既に2回ひかれてるから改めてひかないように-から-する
  	cout<<b-a+1-sum<<endl;//ｂ以下でa以下じゃなくて約数じゃないやつを出す
  

}