#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<(n);i++)
#define init(a,i) for(int k=0;k<(i);k++)(a)[k]=0
#define in(a,i) for(int k=0;k<(i);k++)cin>>(a)[k]
struct factoring
{
private:
	//素数
	vector<int>  prime;
	int find_SPF(int n){
		for(int i=0;prime[i]<=n/prime[i];i++)
			if(n%prime[i]==0)return prime[i];
		return n;
	}
public:
	vector<int> SPF;
	//前処理
	factoring(int max){
		//(素数列挙）
		bool num[max+1];
		num[0]=0;
		num[1]=0;
		for(int i=2;i<=max;i++)num[i]=1;
		//ふるい
		for(int i=2;i<=max/i;i++)
			if(num[i]==1)
				for(int j=2;i<=max/j;j++)
					num[i*j]=0;
		
		for(int i=0;i<max+1;i++)
			if(num[i]==1)prime.emplace_back(i);
		
		//SPFを求める
		SPF.emplace_back(0);
		SPF.emplace_back(1);
		for(int i=2;i<=max;i++)SPF.emplace_back(factoring::find_SPF(i));	
	}
};
int main(){
	factoring s(1000000);
	int n;
	cin >> n;
	int a[n];
	in(a,n);
	int tmp,tmp2;
	bool flag=1,num[1000001];
	init(num,1000001);
	rep(i,n){
		tmp=a[i];
		while(tmp!=1){
			tmp2=s.SPF[tmp];
			if(num[tmp2]==1)flag=0;
			num[tmp2]=1;
			while(!(tmp%tmp2))tmp/=tmp2;
		}
	}
	if(flag==1){
		cout<<"pairwise coprime";
		return 0;
	}
	
	int g;
	g=a[0];
	rep(i,n)g=gcd(g,a[i]);
	if(g==1)cout << "setwise coprime";
	else cout<<"not coprime";
	return 0;
}