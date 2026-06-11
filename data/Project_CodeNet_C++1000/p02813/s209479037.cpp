#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<(n);i++)
#define init(a,i) for(int k=0;k<(i);k++)(a)[k]=0
#define in(a,i) for(int k=0;k<(i);k++)cin>>(a)[k]
#define all(a)  (a).begin(),(a).end()
#define el(a) (a).end()-(a).begin()

int main(){
	int n;
	cin>>n;
	vector<int> v;
	rep(i,n)v.push_back(i+1);
	int p=0,q=0,tmp;
	rep(i,n){
		cin>>tmp;
		p=p*10+tmp;
	}
	rep(i,n){
		cin>>tmp;
		q=q*10+tmp;
	}
	int count=0,num,a,b;
	do{
		num=0;
		count++;
		for(int& i:v)num=num*10+i;
		if(num==p)a=count;
		if(num==q)b=count;
	}while(next_permutation(all(v)));
	cout<<abs(b-a);
	return 0;
}