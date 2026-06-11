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
const ll MOD=1000000007;



int main() {
    string S;
    cin>>S;
    if(S.at(0)==S.at(1)){
        if(S.at(2)!=S.at(1)){
            if(S.at(3)==S.at(2)){cout<<"Yes"<<endl;return 0;}
        }
    }
    swap(S.at(1),S.at(2));
    if(S.at(0)==S.at(1)){
        if(S.at(2)!=S.at(1)){
            if(S.at(3)==S.at(2)){cout<<"Yes"<<endl;return 0;}
        }
    }
    swap(S.at(1),S.at(3));
    if(S.at(0)==S.at(1)){
        if(S.at(2)!=S.at(1)){
            if(S.at(3)==S.at(2)){cout<<"Yes"<<endl;return 0;}
        }
    }
    cout<<"No"<<endl;
}