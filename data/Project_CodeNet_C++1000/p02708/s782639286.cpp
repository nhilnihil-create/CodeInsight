#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define int long long
using namespace std;
using P=pair<int,int>;
using Graph=vector<vector<int>>;
using ll=long long;


vector<pair<int,int>> soinsuu(int n){
    vector<pair<int,int>> ret;
    for(int i=2;i*i<=n;i++){
        if(n%i !=0) continue;
        int ex=0;
        while(n%i ==0){
            ex++;
            n /= i; //n変更することで、それ以降の約数で割り切れることはない
        }
        ret.push_back(make_pair(i,ex));
    }
    //nが素数だった場合
    if(n!=1) ret.push_back(make_pair(n,1));
    return ret;
}

int mod=pow(10,9)+7;

signed main(){ 
    int n,k; cin>>n>>k;

    int sum=0;

    for(int i=k;i<=(n+1);i++){
        int sma=i*(i-1)/2;
        int big=n*(n+1)/2 - (n-i+1)*(n-i)/2;

        sum+=(big-sma+1LL)%mod;
    }

    cout<<sum%mod<<endl;
}  