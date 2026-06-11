#include<cstdio>
#include<algorithm>
#include<cstring>
#include<functional>
#include<iostream>
#define rep(i,a) for(i=1;i<=a;i++)
using namespace std;
int main(void)
{
	int n,i,x;
	cin>>n;
	rep(i,n) {
		if(i%3==0) cout<<" "<<i;
		else {
			x=i;
			while(x>0) {
				if(x%10==3) {cout<<" "<<i;break;}
				else x=x/10;
			}
		}
	}
	cout<<endl;
	return 0;
}