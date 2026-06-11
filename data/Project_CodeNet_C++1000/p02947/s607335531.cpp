//全然分からなかったから見返すとき用
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())

ll choose(ll a) { //aC2
	return (a - 1) * a / 2;//組み合わせを求める式
  							//3つ同じなら3-1*3/2で4組になるので
}
int main() {
	ll n;// 32 bit 整数型に収まらない可能性がある
  	cin>>n;
  
  	vector<string> s(n);
 	rep (i,n)cin>>s[i];
  	rep (i,n)SORT(s[i]);//sortで辞書順並び替えできる
  	SORT(s);
  
  	vector <ll> cnt(n,1);
	ll sum=0;//最後の答えのやつ
  	ll j=0;//
  
  	rep(i,n-1){
    	if(s[i]==s[i+1])
          cnt[j]++;//一致した数
      	else j++;
    }
	j++;
  	rep(i,j)sum+=choose(cnt[i]);//一致した数から組み合わせ数を求める
  	cout<<sum<<endl;
  
}