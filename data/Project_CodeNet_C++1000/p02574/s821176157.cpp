#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000010];
vector<int> v;
bool flag[1000010];
map<int,bool> mp;
int main(){
	cin>>n;
	flag[0]=1;
	flag[1]=1;
	for(int i=2;i<=1000000;i++){
		if(!flag[i]){
			v.push_back(i);
			for(int j=i+i;j<=1000000;j+=i){
				flag[j]=1;
			}
		}
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int gcd=a[0];
	for(int i=1;i<n;i++){
		gcd=__gcd(gcd,a[i]);
	}
	if(gcd!=1){
		cout<<"not coprime"<<endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		int x=0;
		while(a[i]>1){
			if(!flag[a[i]]){
				if(mp[a[i]]){
					cout<<"setwise coprime"<<endl;
					return 0;
				}
				mp[a[i]]=1;
				break;
			}
			while(x<v.size()&&a[i]%v[x]!=0){
				x++;
			}
			if(mp[v[x]]){
				cout<<"setwise coprime"<<endl;
				return 0;
			}
			mp[v[x]]=1;
			while(a[i]%v[x]==0){
				a[i]/=v[x];
			}
		}
	}
	cout<<"pairwise coprime"<<endl;
	return 0;
}