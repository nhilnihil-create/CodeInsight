#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> data(n);
    rep(i,0,n){
        data[i]=s[i];
    }
    set<int> cnt;
    vector<int> variety(n+1);
    for(int i = n-1;i>=0;i--){
        cnt.insert(data[i]);
        variety[i]=cnt.size();
    }
    
    ll ans = 0;
    set<int> first;
    rep(i,0,n){
        
        if(!first.count(data[i])){
            first.insert(data[i]);
            set<int> second;
            rep(j,i+1,n){
                
                if(!second.count(data[j])){
                    ans += variety[j+1];
                    second.insert(data[j]);
                }
            }
        }
    }
    cout<<ans<<endl;
    
    

    return 0;
}
