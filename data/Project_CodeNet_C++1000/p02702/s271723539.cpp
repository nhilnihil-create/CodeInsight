#include<bits/stdc++.h>
using namespace std;
int moder = 2019;
map<int,int>m;
map<int,int>::iterator it;
long long tenth[200005];

int main(){
	tenth[0] = 1;
	for(int i=1; i<=200000; i++){
		tenth[i] = tenth[i-1]*10;
		tenth[i]%=moder;
	}
	string s;
	cin>>s;
	vector<int>arr((int)s.length());
	for(int i=0; s[i]; i++) arr[i] = (int)(s[i]-'0');
	m.insert(make_pair(0,1));
	long long curr = 0;
	int ret = 0;
	for(int i=0; i<arr.size(); i++){
		curr*=10;
		curr+=arr[i];
		curr%=moder;
		long long temp = curr*tenth[s.length()-1-i];
		temp%=moder;
		it = m.find((int)temp);
		if(it!=m.end()){
			ret+=it->second;
			it->second+=1;
		}
		else m.insert(make_pair((int)temp,1));
	}
	cout<<ret;
}
