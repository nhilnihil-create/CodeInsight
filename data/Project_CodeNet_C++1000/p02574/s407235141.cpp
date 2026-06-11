#include<bits/stdc++.h>
using namespace std;

const int N = 1000100;
int prime[N];
int a[1000100] = {0};
int cnt = 1;
bool vis[N];

void prepare(int n)
{
	for(int i = 2;i<=n;++i){
		if(vis[i] == 0){
			prime[cnt] = i;
			cnt++;
		}
		for(int j = 1;j<cnt;++j){
			if(i*prime[j]>n) break;
			vis[i*prime[j]] = 1;
			if(i*prime[j] == 0) break;
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	prepare(N);
	int n;
	cin>>n;
	for(int i = 1;i<=n;++i){
		int x;
		cin>>x;
		int ex = x;
		if(vis[x] == 0) a[x]++;
		for(int i = 1;i<cnt;++i){			
			if(prime[i]*prime[i]<=x && x%prime[i] == 0){
				a[prime[i]]++;				
				while(x%prime[i] == 0) x /= prime[i];
			}
			if(prime[i]*prime[i]>x) break;
		}
		if(vis[x] == 0 && x != ex) a[x]++;
	}
	int flag = 0,flagn = 0;
//	for(int i = 1;i<=15;++i) cout<<a[i]<<" ";
//	cout<<endl;
	
	for(int i = 2;i<1000100;i++){
		if(a[i]>=2) flag++;
		if(a[i] == n) flagn++;
	}
	
	if(flag == 0) cout<<"pairwise coprime"<<endl;
	else if(flagn == 0) cout<<"setwise coprime"<<endl;
	else cout<<"not coprime"<<endl;
//	for(int i = 1;i<cnt;++i)  cout<<prime[i]<<endl;
	return 0; 
} 