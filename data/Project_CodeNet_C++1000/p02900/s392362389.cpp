#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using namespace std;

long long gcd(long long a,long long b){
	long long x=max(a,b),y=min(a,b);
	if(x%y==0)return y;
	else return gcd(y,x%y);
}

int main(){
	
	long long a,b;
	cin >> a >> b;
	
	long long ma=max(a,b);
	long long mi=min(a,b);
	long long g=gcd(mi,ma);
	
	map<long long , long long> mp;
	mp[1]=1;
	
	long long base=g;
	for(long long i=2;i*i<=base;i++){
		if(g%i==0){
			mp[i]=1;
			while(1){
				if(g%i!=0)break;
				g/=i;
			}
		}
	}
	mp[g]=1;
	long long ans=0;
	for(auto p : mp){
		ans++;
	}
	cout << endl;
	cout << ans << endl;
	return 0;
}
