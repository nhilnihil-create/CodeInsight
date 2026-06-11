#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<(n);i++)
#define init(a,i) for(int k=0;k<(i);k++)(a)[k]=0
#define in(a,i) for(int k=0;k<(i);k++)cin>>(a)[k]
#define all(a)  (a).begin(),(a).end()
#define el(a) (a).end()-(a).begin()
#define mod 1000000007
#define inf 2147483647
int main(){
	int n;
	cin>>n;
	int num[10][10],top_num=0,top_dig=1;
	rep(i,10)rep(j,10)num[i][j]=0;
	for(int i=1;i<=n;i++){
		if(!(i%top_dig))top_num++;
		if(top_num==10){
			top_dig*=10;
			top_num=1;
		}
		num[top_num][i%10]++;
	}
	int sum=0;
	rep(i,10)rep(j,10)sum+=num[i][j]*num[j][i];
	cout << sum;
	return 0;
}