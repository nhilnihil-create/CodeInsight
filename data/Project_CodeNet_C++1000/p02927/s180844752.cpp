#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int M,D;
    cin>>M>>D;
    int count=0;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=D;j++){
            int x=j/10;
            int y=j%10;
            if(x>1 && y>1 && i==x*y)count++;
        }
    }
    cout<<count<<endl;
}