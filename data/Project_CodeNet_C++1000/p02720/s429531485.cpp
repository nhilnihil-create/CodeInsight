#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

    vector<vector<ll>> dp(11);

    for(ll i=1;i<10;i++)dp[1].push_back(i);
    for(ll i=2;i<11;i++){
        for(ll j=0;j<dp[i-1].size();j++){
            ll a=dp[i-1][j];
            if(a%10==0){
                dp[i].push_back(a*10);
                dp[i].push_back(a*10+1);
            }
            else if(a%10==9){
                dp[i].push_back(a*10+8);
                dp[i].push_back(a*10+9);
            }
            else{
                dp[i].push_back(a*10+a%10);
                dp[i].push_back(a*10+a%10-1);
                dp[i].push_back(a*10+a%10+1);
            }
        }
    }
    

    vector<long long int> b;

    
    
    for(int i=1;i<11;i++){
        for(int j=0;j<dp[i].size();j++){
            b.push_back(dp[i][j]);
        }
    }
    

    sort(b.begin(),b.end());

    //cout << b.size() << endl;


    int d;

    cin >> d ;

    cout << b[d-1] << endl; 

}