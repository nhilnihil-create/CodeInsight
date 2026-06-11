//============================================================================
// Name        : e.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	int n,k,c;cin>>n>>k>>c;
	vector<int> f,b;
	string s;cin>>s;
	for(int i=0;i<n;i++){
		if(f.size()==0){
			if(s[i]=='o'){
				f.push_back(i);
			}
		}else{
			if(s[i]=='o'){
				if(i>c+f.back()){
					f.push_back(i);
				}
			}
		}
	}
	if(f.size()>k){
		return 0;
	}
	for(int i=n-1;i>=0;i--){
		if(b.size()==0){
			if(s[i]=='o'){
				b.push_back(i);
			}
		}else{
			if(s[i]=='o'){
				if(i<b.back()-c){
					b.push_back(i);
				}
			}
		}
	}
	vector<int> count(n,0);
	for(int i=0;i<k;i++){
		count[f[i]]++;
		count[b[i]]++;
	}
	for(int i=0;i<n;i++){
		if(count[i]==2){
			cout<<i+1<<endl;
		}
	}
	return 0;
}
