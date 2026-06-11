#include <bits/stdc++.h>
using namespace std;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long 

int odd[10101010],even[10101010];
int main() {
	vector<int>a,b;
	int cnt=0;
	for(int i=1;i<=10101010;i++){
		int x=i*(i+1)*(i+2)/6;
		if(x>10101010)break;
		a.push_back(x);
		if(x%2==1) b.push_back(x);
	}
	//cout<<"kazua"<<a.size()<<" kazub"<<b.size()<<endl;
	rep(i,a.size()){
		int cnt=1;
		while(a[i]*cnt<10101010){
    		if(a[i]*cnt<10101010){
				even[a[i]*cnt]=cnt;
			}else break;
			cnt++;
		}
	}
	rep(i,b.size()){
		int cnt=1;
		while(b[i]*cnt<10101010){
			if(b[i]*cnt<10101010){
				odd[b[i]*cnt]=cnt;
			}else break;
			cnt++;
		}
	}
	
		//rep(i,1010101){odd[i]=1010101;}
		//rep(i,1010101){even[i]=1010101;}
		rep(j,a.size()){
			for(int i=0;i<10101010;i++){
				if(even[i]!=0&&i+a[j]<10101010)chmin(even[i+a[j]],even[i]+1);
			}
		}
		rep(j,b.size()){
    		for(int i=0;i<10101010;i++){
				if(odd[i]!=0&&i+b[j]<10101010)chmin(odd[i+b[j]],odd[i]+1);
			}
		}
	int n=1;
	while(cin>>n){
		if(n==0)break;
		cout<<even[n]<<" "<<odd[n]<<endl;
	}
	return 0;
}
