#include <bits/stdc++.h> 

using namespace std; 

int main() 
{ 
	int n1,n2;
	
	cin>>n1>>n2;
	
	int a[n1],b[n2];
	
	for(int i = 0 ; i < n1 ; i++) cin>>a[i];
	for(int i = 0 ; i < n2 ; i++) cin>>b[i];
	
	long long int cnt[n1+1][n2+1];
	memset(cnt,0,sizeof(cnt));

    for(int i = 0 ; i < n1 ; i++){
        for(int j = 0 ; j < n2 ; j++){
            if(a[i]==b[j]) {cnt[i+1][j+1] = (cnt[i][j+1]+cnt[i+1][j]+1)%1000000007;}
            else {cnt[i+1][j+1] = (cnt[i][j+1]+cnt[i+1][j]-cnt[i][j])%1000000007;}
        }
    }
	cout <<(cnt[n1][n2]+1+1000000007)%1000000007<<endl; 
	return 0; 
} 
