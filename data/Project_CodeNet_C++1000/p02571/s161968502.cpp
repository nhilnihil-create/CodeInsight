#include<iostream>
#include<algorithm>
using namespace std;

const int INF=100000010;

int main(){
	string s,t;
	cin>>s>>t;
	int ans=INF;
	for(int i=0;i<s.size()-t.size()+1;i++){
		int count=0;
		for(int j=0;j<t.size();j++){
			if(s.at(i+j)!=t.at(j)){
				count++;
			}
		}
		ans=min(ans,count);
	}
	cout<<ans<<endl;
}