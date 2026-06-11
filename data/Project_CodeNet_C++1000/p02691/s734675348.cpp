#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int MR=1e6+10;
typedef long long LL;

map<LL,LL> myset;

int main() {
	LL n,a,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		cnt+=myset[a-i];
		if(myset.count(-a-i)){
			myset[-a-i]+=1;
		}
		else{
			myset[-a-i]=1;
		}
	}
	cout<<cnt<<endl;
    return 0;
}