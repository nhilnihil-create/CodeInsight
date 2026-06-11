#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
 
int main(){
	
	int n,k,c; string s;
	cin>>n>>k>>c>>s;
	vector<int> t1(n),t2(n);
	for(int i=0; i<n; i++){
		t1.at(i)=n*2+1;
		t2.at(i)=n*3+1;
	}
	int cnt{},i{};
	while(i<n){
		if(s.at(i)=='o'){
			cnt++;
			t1.at(i)=cnt;
			if(cnt==k) break;
			i+=c+1;
		}
		else i++;
	}
	i=n-1;
	while(i>=0){
		if(s.at(i)=='o'){
			t2.at(i)=cnt;
			cnt--;
			if(cnt==-1) break;
			i-=c+1;
		}
		else i--;
	}
	for(int i=0; i<n; i++){
		if(t1.at(i)==t2.at(i)) cout<<i+1 << endl;
	}
	
}
