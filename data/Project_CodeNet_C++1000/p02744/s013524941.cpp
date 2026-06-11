#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;
typedef pair<ll,ll> pll;
typedef priority_queue<string> priquest;
typedef priority_queue<string,vector<string>,greater<string>> rpriquest;
ll max(ll x,ll y){
if(x>y)return x;
else return y;
}
ll min(ll x,ll y){
  return x+y-max(x,y);
}

const ll big=1000000007;
int exp(int x,int y){
    if(y==0)return 1;//0^0=1
    if(x==1||x==0)return x;
    if(y%2==1)return (exp(x,y-1)*x)%big;
    int t=exp(x,y/2);
    return (t*t)%big;
}
void chmin(ll a,ll b){
    if(a>b)a=b;
    return;
}

//sに現れた文字種類
int count(string s){
    map<char,int> ans;
    rep(i,s.size())ans[s[i]]=1;
    return ans.size();
}


rpriquest func(int n){
    rpriquest ans;
    if(n==1){
        ans.push("a");return ans;
    }
    rpriquest last=func(n-1);
    while(!last.empty()){
        string now=last.top();last.pop();
        rep(i,count(now)+1){
            char k='a'+i;
            ans.push(now+k);
        }
    }
    return ans;
}

int main(){
    int n;cin >> n;
    rpriquest ans=func(n);
    while(!ans.empty()){
        cout << ans.top() << endl;
        ans.pop();
    }
}