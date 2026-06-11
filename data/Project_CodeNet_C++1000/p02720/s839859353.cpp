#include<bits/stdc++.h>
using namespace std;
int cnt=0,len,k;
long long ans;
void dfs(int x,long long i){
    if(len==x){
	    cnt++;
    	if(cnt==k)
	    	ans=i;
		i/=10;
		return;
	}
    long long u=i%10;
    for(long long j=u-1;j<=u+1;j++){
        if(j<0 || j>9) continue;
        else{
            len++;
            dfs(x,i*10+j);
            len--;
        }
    }
}
int main(){
    cin>>k;
    for(int j=1;j<=10;j++){
        for(long long i=1;i<=9;i++){
            len=1;
            dfs(j,i);
        }
    }
    cout<<ans;
    return 0;
}