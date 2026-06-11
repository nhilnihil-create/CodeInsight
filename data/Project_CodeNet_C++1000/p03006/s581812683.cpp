#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include<math.h>
using namespace std;
#define INF 10000000
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,ll> P;

int C[60];

P s[3000];

void reset(){
    for(int i=0;i<60;i++) C[i]=0;
}

int main(){
    ll x[60],y[60],temp=0,ans=0;
    int N,count=0;
    cin>>N;

    for(int i=0;i<N;i++) cin>>x[i]>>y[i];

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            s[count].first=x[j]-x[i]; s[count].second=y[j]-y[i];
            count++;
        }
    }

    for(int i=0;i<count;i++,temp=0){
        for(int j=0;j<count;j++){
            if(s[i].first==s[j].first && s[i].second==s[j].second || s[i].first==-s[j].first && s[i].second==-s[j].second){
                temp++;
            }
        }
        ans=max(ans,temp);
    }
    cout<<N-ans<<endl;
}
