#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ret return
using namespace std;
bool p[102]={false};
int main() {
	int x,n,num;
	cin>>x>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		p[num]=true;
	}
	int diff=1e9;
	for(int i=0;i<=100;i++)
		if(!p[i])
			diff=min(diff,abs(x-i));
	int sol=1e9;
	for(int i=0;i<=100;i++)
		if(abs(x-i)==diff&&!p[i])
			sol=min(sol, i);

	if(abs(101-x)<diff){
		sol=101;
		diff=abs(101-x);
	}
	if(abs(x-(-1))<diff)
		sol=-1;
	
	cout<<sol<<endl;
}


