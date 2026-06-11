#include<iostream>
#include<vector>
using namespace std;
long long a[2000];
long long money=1000;
long long num=0;
int main() {
	int n;
	cin>>n;
	for(int i=0; i<n; i++) cin>>a[i];
	vector<int>v;
	for(int i=0; i<n; i++) {
		if(a[i]!=a[i-1]) {
			v.push_back(a[i]);
		}
	}
	int len=v.size();
	int flag;
 
 
	if(v[1]>v[0]) flag=1;
	else flag=-1;
 
	if(flag==1) {
		num=1000/v[0];
		money=1000-num*v[0];
	}
	bool f=true;
	for(int i=1; i<len; i++) {
		int temp;
		if(v[i]>v[i-1]) {
			temp=1;
		} else {
			temp=-1;
		}
		if(temp!=flag) {
			f=false;
			if(flag==1) {//卖
				money+=num*v[i-1];
				num=0;
			}
			if(flag==-1) {//买
				num=money/v[i-1];
				money=money-num*v[i-1];
			}
			flag=-flag;
		}
	}
	if(f==true) {
		if(flag==1) cout<<1000-1000/v[0]*v[0]+1000/v[0]*v[len-1]<<endl;
		if(flag==-1) cout<<1000<<endl;
	} else {
		if(flag==1) money+=num*v[len-1];
		cout<<money<<endl;
	}
 
}