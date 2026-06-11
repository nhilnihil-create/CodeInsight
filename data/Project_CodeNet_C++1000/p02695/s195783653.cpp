#include <iostream>
#include <bits/stdc++.h>

#define rep(i,z) for(int i = 0; i<(int)(z); i++)
#define rep1(i,z) for(int i = 1; i<=(int)(z); i++)
 
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;
using pear = pair<int,int>;



int n,m,q; 
vector<int> a,b,c,d;
   int ans=0;
void dfs(vector<int> A){
    if(A.size()==n+1){
        int now=0;
        rep(i,q){
            if(A[b[i]]-A[a[i]] == c[i]) now += d[i];
        }
        ans=max(ans,now);
        return;
    }
    A.push_back(A.back());
    while(A.back()<=m){
        dfs(A);
        A.back()++;
    }
}

int main(){
   cin>>n >>m >>q;
   a=b=c=d= vector<int>(q);
   rep(i,q) cin>>a[i] >>b[i] >>c[i] >>d[i];
   dfs(vector<int>(1,1));
   cout<<ans<<endl;
}
