#include<bits/stdc++.h>
using namespace std;
int main(){
	string n;
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(i%2==0){
			if(n[i]!='h'){
				break;
			}else if(n[i+1]!='i'){
				break;
			}
		}else if(i%2==1){
			if(n[i]!='i'){
				break;
			}
		}
		if(i==n.size()-1){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}