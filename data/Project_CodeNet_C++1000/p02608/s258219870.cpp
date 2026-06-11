#include<bits/stdc++.h>
#define ll long long int
#define REP(i,a,b)	for(i=a;i<=b;i++)
#define REPr(i,b,a)	for(i=b;i>=b;i--)
#define umap(x,y) unordered_map(int,int)
#define pb push_back
using namespace std;

void solve(){
    int n,i,j,k;  cin>>n;
    int ans[n+1]={0};
    int p=sqrt(n);
    int x;
    REP(i,1,p){
        REP(j,1,p){
            REP(k,1,p){
                x=(i*i+j*j+k*k)+(i*j)+(i*k)+(j*k);
                if(x<=n)    ans[x]++;
            }
        }
    }

    REP(i,1,n)  cout<<ans[i]<<endl;
}

int main(){
    int t;  t=1;;
    while(t--){
        solve();
    }
}