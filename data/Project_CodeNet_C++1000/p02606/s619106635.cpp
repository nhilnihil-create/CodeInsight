#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
#include <iomanip>
//円周率
#define PI 3.14159265358979323846
//cout << fixed << setprecision(20) << *** << endl;
#define rep(i,N) for(int i=0;i<(int)N;++i)
typedef long long ll;
using namespace std;

//ユークリッド
ll gcd(ll a,ll b){
	ll t;
	if(a<b){
		t=a;
		a=b;
		b=t;
	}
	if(a%b==0)return b;
	return gcd(b,a%b);
}
//階乗
ll Factorial(ll a){
	ll b=1;
	for(ll i=a;i>=1;i--){
		b=b*i;
	}
	return b;
}
//素数判定
bool prime(ll n){
	for(ll i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
//桁数把握
ll keta(ll a){
	ll count=0;
	while(a!=0){
		a=a/10;
		count++;
	}
	return count;
}

//三項演算子　[条件] ? [処理(true)]:[処理(false)]
//printf("%d",N<=100 ? 1:0);

//bit全探索(補集合をすべて列挙)
vector<vector<ll>>bits(ll N){
	vector<vector<ll>> V;
	for(int t=0;t<(1<<N);t++){
		vector<ll> vv;
		for(int i=0;i<N;i++){
			if(t&(1<<i))vv.push_back(i);
		}
		V.push_back(vv);
	}
	return V;
}

//数字(アルファベット順)⇒アルファベット
char AbcNumToChar(ll a){
	if(a==0)return 'a';
	if(a==1)return 'b';
	if(a==2)return 'c';
	if(a==3)return 'd';
	if(a==4)return 'e';
	if(a==5)return 'f';
	if(a==6)return 'g';
	if(a==7)return 'h';
	if(a==8)return 'i';
	if(a==9)return 'j';
	if(a==10)return 'k';
	if(a==11)return 'l';
	if(a==12)return 'm';
	if(a==13)return 'n';
	if(a==14)return 'o';
	if(a==15)return 'p';
	if(a==16)return 'q';
	if(a==17)return 'r';
	if(a==18)return 's';
	if(a==19)return 't';
	if(a==20)return 'u';
	if(a==21)return 'v';
	if(a==22)return 'w';
	if(a==23)return 'x';
	if(a==24)return 'y';
	if(a==25)return 'z';
	return '0';
}

//スペース含めた1行読み込み
//getline(cin,s);

//1～Xのサイコロを振った時の出目の期待値
double kitaichi(ll N){
	double d=0,t;
	for(ll i=1;i<=N;i++){
		t=i/(double)N;
		d=d+t;
	}
	return d;
}


//配列1の固まりの数を数える
//例　11011 ⇒　2
//例　0110111011 ⇒　3
//例　111 ⇒　1
/*
rep(i,Vsize()-1){
	//初手1ならプラス、その他は0,1をカウント
	if(V[i]==1&&j==0)ANS++;
	if(VV[i]==0&&VV[i+1]==1)ANS++;
}
*/

int main()
{
	ll L,R,d,ANS=0;
	cin>>L>>R>>d;
	for(ll i=L;i<=R;i++){
		if(i%d==0)ANS++;
	}
	cout<<ANS<<endl;
}