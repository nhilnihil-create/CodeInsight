#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<string> a;
    queue<string> que;
    que.push("a");
    while(!que.empty()){
        string t=que.front();
        que.pop();
        int k=t.size();
        if(k==n){
            a.push_back(t);
            continue;
        }
        int m=0;
        for(int i=0;i<t.size();i++){
            chmax(m,t[i]-'a');
        }
        for(int i=0;i<=m+1;i++){
            que.push(t+char(i+'a'));
        }
    }
    sort(a.begin(),a.end());
    for(string x:a){
        cout << x << endl;
    }
}