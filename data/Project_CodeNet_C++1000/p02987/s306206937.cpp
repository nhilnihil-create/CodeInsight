#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int count=0;
	cin>>s;
	unordered_map<int,int> mp;
	for(int i=0; i<4; i++){
        if(mp.find(s[i])==mp.end()){
        	mp[s[i]]=1;
        	count++;
		}
	}
	if(count==2){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
}