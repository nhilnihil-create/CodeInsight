#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
bool zs(int x){
	if(x<=1)return false;
	for(int i=2;i*i<=x;i++)
	 if(x%i==0)
	  return false;
	return true;
}
int n,t;
int main(){
	cin>>n;t=n;
	if(zs(n)){cout<<n<<endl;return 0;}
	while(!zs(t))t++;
	cout<<t<<endl;
	return 0;
}
