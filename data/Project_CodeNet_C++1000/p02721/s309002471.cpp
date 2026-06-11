#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,int>
#define T tuple<int,int,int> 
using namespace std;

int main(){
    int n,k,c; cin >> n >> k >> c;
    string s; cin >> s;
    vector<int> ssum(n+1);
    vector<int> swhere(n+1);
    ssum[0]=0;
    swhere[0]=-1;
    rep(i,n){
        if(s[i]=='o'){
            ssum[i+1]=ssum[i]+1;
            swhere[i+1]=i+1;
        }
        else{
            ssum[i+1]=ssum[i];
            swhere[i+1]=swhere[i];
        }
    }

    vector<int> donyoku;
    int now=0;
    while(now<n && donyoku.size()<k){
        if(s[now]=='x'){
            now++;
            continue;
        }
        donyoku.push_back(now+1);
        now+=c+1;
    }
    
    reverse(all(donyoku));

    vector<int> ans;

    int after=-1;
    rep(i,donyoku.size()){
        int cu=donyoku[i];
        int r=n;
        if(after!=-1) r=max(1,after-c-1);
        if(ssum[r]==ssum[cu]){
            ans.push_back(cu);
            after=cu;
        }
        else{
            after=swhere[r];
        }
    }

    reverse(all(ans));
    rep(i,ans.size()) cout << ans[i] << endl;
    return 0;
}
