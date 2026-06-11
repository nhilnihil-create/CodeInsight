#include<iostream>
#include<cstring> 
using namespace std;
int a[10];
bool vis[10];
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(vis, 0, sizeof vis);
		for(int i = 0; i < 10; i++) cin>>a[i];
		int now = 0;
		for(int i = 1; i < 10; i++){
			if(a[i] > a[now]){
				now = i;
				vis[now] = 1;
			}
		}
		bool flag = true;
		now = -1;
		for(int i = 1; i < 10; i++){
			if(!vis[i]){
				if(now == -1) now = i;
				else{
					if(a[i] < a[now]){
						flag = false;
						break;
					}
					else now = i;
				}
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}