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

vector<vector<int>> ans(500,vector<int> (500));
void level(int L,int from,int to){
    int num=to-from+1;
    if(num==2){
        ans.at(from).at(to)=L;
        ans.at(to).at(from)=L;
        return;
    }
    if(num==3){
        ans.at(from).at(to-1)=L;
        ans.at(from).at(to)=L;
        ans.at(to-1).at(to)=L+1;
        return;
    }
    int newto,newfrom;
    newfrom=num/2+from;
    newto=newfrom-1;
    for(int i=from;i<=newto;i++){
        for(int j=newfrom;j<=to;j++){
            ans.at(i).at(j)=L;
            ans.at(j).at(i)=L;
        }
    }
    level(L+1,from,newto);
    level(L+1,newfrom,to);
    return;
}

int main() {
    int N;
    cin>>N;
    level(1,0,N-1);
    rep(i,N-1){
        for(int j=i+1;j<N;j++){
            cout<<ans.at(i).at(j);
            if(j==N-1){cout<<endl;}
            else{cout<<" ";}
        }
    }
}