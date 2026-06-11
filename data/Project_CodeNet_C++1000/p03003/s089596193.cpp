#include <bits/stdc++.h> 

using namespace std; 

int main() 
{ 
    long long int n1,n2,e=1000000007;
	
	cin>>n1>>n2;
	
	long long int a[n1],b[n2];
	
	for(long long int i = 0 ; i < n1 ; i++) cin>>a[i];
	for(long long int i = 0 ; i < n2 ; i++) cin>>b[i];
	
	long long int cnt[n1+1][n2+1];
	memset(cnt,0,sizeof(cnt));

    for(long long int i = 0 ; i <= n1 ; i++){
        for(long long int j = 0 ; j <= n2 ; j++){
            if(i==0||j==0) {cnt[i][j] = 1;}
            else{
                cnt[i][j] = (cnt[i-1][j]%e+cnt[i][j-1]%e-cnt[i-1][j-1]%e)%e;
                if(a[i-1]==b[j-1]){
                    cnt[i][j] += (cnt[i-1][j-1])%e;
                }
            }
        }
    }
    
    //printf("%llu\n",(cnt[n1][n2])%e);
	cout <<(cnt[n1][n2]+e)%e<<endl;
	return 0; 
} 
