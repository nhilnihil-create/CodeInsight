#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int>P;
typedef tuple<int,int,int,int>T;
#define PI 3.14159265359
#define MOD 1000000007
const int MAX =510000;

int main(){
  	string S;
  	cin >>S;
  	ll N=S.size();
  	ll dp[13][N+1];
  	rep(i,13){rep(j,N+1){dp[i][j]=0;}}
  	ll memo[N+1];
  	rep(i,N+1){memo[i]=0;}
  	memo[0]=1;
  	rep(i,N){
      memo[i+1]=(memo[i]*10)%13;
    }
  	char p=S[N-1];
  	if(p=='?'){rep(i,10){dp[i][0]=1;}}
  	else{
        int g=p-'0';
        dp[g][0]=1;
    }
  	for(int i=1;i<=N-1;i++){
    	int b=memo[i];	
    	if(S[N-i-1]!='?'){
        	int g=S[N-i-1]-'0';
          	g=(g*b)%13;
          	for(int j=0;j<=12;j++){
              if(j+g<=12){dp[j+g][i]+=dp[j][i-1];dp[j+g][i]%=MOD;}
              else{dp[j+g-13][i]+=dp[j][i-1];dp[j+g-13][i]%=MOD;}
            }
        }	
    	else{
          rep(h,10){
            	int g=(h*b)%13;
            for(int j=0;j<=12;j++){
              if(j+g<=12){dp[j+g][i]+=dp[j][i-1];dp[j+g][i]%=MOD;}
              else{dp[j+g-13][i]+=dp[j][i-1];dp[j+g-13][i]%=MOD;}
            } 	
          }
        }//else
    }
  	cout<<dp[5][N-1]<<endl;
}
