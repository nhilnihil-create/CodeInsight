#include<bits/stdc++.h>
using namespace std;
vector<long long> v;
void digui(long long cur,int time){
	if(time==0)return;
	int last_digit=cur%10;
	v.push_back(cur*10+last_digit);
	if(last_digit!=9)v.push_back(cur*10+last_digit+1);
	if(last_digit!=0)v.push_back(cur*10+last_digit-1);
	digui(cur*10+last_digit,time-1);
	if(last_digit!=9)digui(cur*10+last_digit+1,time-1);
	if(last_digit!=0)digui(cur*10+last_digit-1,time-1);
}
int main()
{
	int k;cin>>k;
	for(int i=1;i<10;i++){
		v.push_back(i);
		digui(i,10);
	}
	sort(v.begin(),v.end());
	cout<<v[k-1];
	return 0;
}