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
int flag=1;
int c=0;
int k;
void runnrunn(int number,int place,string s){
	char num='0'+number;
	s+=num;
	if(place==1){
		c++;
		if(c==k){
			cout <<s;
			flag=0;
		}
		return;
	}
	else{
		if(number-1>=0 && flag)runnrunn(number-1,place-1,s);
		if(flag)runnrunn(number,place-1,s);
		if(number+1<=9&&flag)runnrunn(number+1,place-1,s);
	}
	return;
}
		
int main(){
	cin>>k;
	string s;
	int i=0;
	while(flag){
		i++;
		rep(j,9){
			runnrunn(j+1,i,s);
		}
	}
	return 0;
}