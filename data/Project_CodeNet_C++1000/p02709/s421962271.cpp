#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<stdio.h>
#include<stack>
#include<math.h>
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define Rep(i,n) for(int i=1;i<=(n);i++)
#define LL long long int
#define MOD 1000000007
 
 
using namespace std;
 
LL lcm(LL n, LL m)
{
	LL u;
	LL ansl = 0;
	for(u=m; u>=m; u++){
		if(u%n == 0){
			if(u%m == 0){
				ansl = u;
				break;
			}
		}
	}
	return ansl;
}
 

int main(){
    int n;
    cin >>n;

    vector<pair<LL,int>> a(n);
    rep(i,n){
        cin >>a[i].first;
        a[i].second=i;
    }
    sort(a.begin(),a.end(), greater<>());
    vector<vector<LL>> dp(n+1,vector<LL>(n+1,0));
    LL l,r,i,ans=0;

 //   rep(i,n){
//        cout<<a[i].first<<" "<<a[i].second<<endl;
 //   }


    for(int x=0;x<(n);x++){
        for(int y=0;y<(n);y++){

//            cout<<" "<< x<<" "<<y<<" "<<dp[x][y]<<"    ";

            if(x+y==0)continue;
            i=a[x+y-1].second;
            if(x!=0){
                l=dp[x-1][y]+(a[x+y-1].first) *(i-x+1);
                
            }
            else{
                l=0;
            }
            if(y!=0){
                r=dp[x][y-1]+(a[x+y-1].first) *((n-y)-i);
                
            }
            else{
                r=0;
            }
            dp[x][y]=max(r,l);
//            ans=max(ans,dp[x][y]);
//            cout <<r<<","<<l<<" l "<<dp[x][y]<<endl;

        }
    }
    rep(i,n){
        ans=max(ans,dp[i][n-i]);
    }
    cout<<ans<<endl;
}