#include<cmath>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<functional>
#define INF 1e16
#define N (1000000000+7)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,P> Q;


ll gcd(ll a, ll b) {
    if(b==0) return abs(a);
	else return gcd(b, a%b);
}

const int inf = 1<<30;

int main(void){
    int n,m;
    string s;
    cin>>n>>m>>s;
    vector<int>dp(n+1,inf);
    dp[n]=0;
    queue<int>q;
    q.push(0);
    for(int i=n-1;i>=0;--i){
        while(1){
            if(q.size()==0){
                cout<<"-1"<<endl;
                return 0;
            }
            if(q.front() != inf && q.size()<=m)break;
            q.pop();
        }
        if(s[i]=='0')dp[i]=q.front()+1;
        q.push(dp[i]);
    }
    vector<int>ans;
    int x = 0;
    int rest = dp[0];
    while(x<n){
        --rest;
        int i=1;
        while(dp[x+i]!=rest)++i;
        ans.push_back(i);
        x += i;
    }
    for(int i=0;i<ans.size();i++){
        if(i==ans.size()-1)cout<<ans[i]<<endl;
        else cout<<ans[i]<<" ";
    }
    return 0;
}