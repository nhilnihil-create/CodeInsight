#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,temp,flag=0,sum=0;
	cin>>n;
	unordered_set<int> s;
	map<int,int> ma;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		s.emplace(a[i]);
		ma[a[i]]++;
	}
	for(int i=0;i<n;i++){
		if(ma[a[i]]>1)
		continue;
		flag=0;
		for(int j=1;j<=sqrt(a[i]);j++){
			if(a[i]%j==0){
				if(j!=a[i]){
					if(s.find(j)!=s.end()){
						flag=1;
						break;
					} 					
				}
				if((a[i]/j)!=a[i]){
					if(s.find(a[i]/j)!=s.end()){
						flag=1;
						break;
					}					
				}
			}
		}
		if(!flag) {
			//cout<<a[i]<<endl;
			sum++;
		}
	}
	cout<<sum<<endl;
}