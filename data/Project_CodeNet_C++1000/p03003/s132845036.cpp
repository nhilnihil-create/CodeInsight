#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include<set>
#include<tuple>
using namespace std;
#define INF 11000000000
#define MAX 100000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
typedef pair<pair<int,int>,int> p;
typedef pair< pair<int,int>, int> p; 
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)

//http://kmjp.hatenablog.jp/entry/2019/06/17/0930

ll sum[2100][2100];
ll num[2100][2100];

int main(){
    int N,M;
    cin>>N>>M;
    int S[2100],T[2100];
    for(int i=0;i<N;i++) cin>>S[i];
    for(int i=0;i<M;i++) cin>>T[i];

    for(int i=0;i<2100;i++) sum[i][0]=sum[0][i]=1;
    ll ans=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(S[i]==T[j]){
                num[i+1][j+1]=(sum[i][j])%MOD;
                ans+=num[i+1][j+1];
            }
            sum[i+1][j+1]=(sum[i][j+1]+sum[i+1][j]+MOD-sum[i][j]+num[i+1][j+1])%MOD;
        }
    }
    cout<<ans%MOD<<endl;
}

