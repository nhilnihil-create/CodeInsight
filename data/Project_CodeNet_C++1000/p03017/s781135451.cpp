#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int n,a,b,c,d;
string S;
bool dp[201010];
bool isok(int s,int t){
    for(int i=s;i<=t;i++) dp[i]=false;
    dp[s]=true;
    for(int i=s;i<=t;i++){
        if(dp[i]){
            for(int d=1;d<=2;d++){
                if(S[i]=='.') dp[i+d]=true;
            }
        }
    }
    return dp[t];
}

int main(){
    
    cin>>n>>a>>b>>c>>d>>S;
    a--,b--,c--,d--;

    if(!isok(a,c)){
        cout<<"No"<<endl;
        return 0;
    }

    if(!isok(b,d)){
        cout<<"No"<<endl;
        return 0;
    }

    if(c<d){
        cout<<"Yes"<<endl;
        return 0;
    } 

    for(int i=b-1;i<d;i++){
        if(S[i]=='.' && S[i+1]=='.' && S[i+2]=='.'){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}