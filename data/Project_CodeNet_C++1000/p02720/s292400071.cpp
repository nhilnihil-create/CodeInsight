#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod =1e+9+7;

int main(){
    ll k; cin>>k;
    queue<ll>q;
    rep(i,9){
        q.push(i+1);
    }
    for(ll i=1;;i++){
        ll a=q.front();
        q.pop();
        if(i==k){
            cout<<a<<endl;
            return 0;
        }
        else{
            for(int j=a%10-1;j<=a%10+1;j++){
                if(j<0||j>=10)continue;
                q.push(a*10+j);
            }
        }
    }
}






































