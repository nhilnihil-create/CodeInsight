#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)
#define pb push_back

int a,b,c;
bool input(){
	cin>>a>>b>>c;
	if(c==0)return false;
	return true;
}

int calc(int zei, int val){
	return val * (zei+100)/100;
}

void solve(){
	
	int maxi = -1;
	reps(i,1,1001){
		reps(j,1,1001){
			int t1 = calc(a,i) + calc(a,j);
			int t2 = calc(b,i) + calc(b,j);
			
			if(t1==c){
				if(t2==27){
				}
				maxi = max(maxi, t2);
			}
		}
	}
	cout<<maxi<<endl;
}

int main(){
	while(input())solve();
}