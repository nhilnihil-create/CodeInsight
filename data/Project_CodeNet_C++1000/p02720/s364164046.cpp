#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

vector<ll> v;

void dfs(string s){
    ll lun=stoll(s);
    if(lun<=3234566667){
        v.push_back(lun);
        rep(i,10){
            int x=s.back()-'0';
            if(abs(x-i)>1) continue;
            char c=char(i+'0');
            dfs(s+c); 
        }
    }
}

int main(){
    int k;
    cin>>k;
    dfs("1");
    dfs("2");
    dfs("3");
    dfs("4");
    dfs("5");
    dfs("6");
    dfs("7");
    dfs("8");
    dfs("9");

    

    sort(all(v));
    cout<<v[k-1]<<endl;
} 
