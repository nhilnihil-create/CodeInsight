#include<bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int N,M,Q;
vector<int> a,b,c,d;
int res = 0;
void dfs(vector<int> &A){
    if(A.size()==N){
        //得点check
        int tmp_res = 0;
        rep(i,Q){
            if(A.at(b.at(i))-A.at(a.at(i))==c.at(i))tmp_res+=d.at(i);
        }
        chmax(res,tmp_res);
        return;
    }

    for(int v = 1; v <= M; v++){
        if(A.size()!=0){
            int A_end = A.back();
            if(A_end>v)continue;
        }
        A.push_back(v);
        dfs(A);
        A.pop_back();
    }
}

int main(){
    cin>>N>>M>>Q;
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);
    rep(i,Q){
        cin>>a.at(i)>>b.at(i)>>c.at(i)>>d.at(i);
        a.at(i)--; b.at(i)--;
    }
    vector<int> A;
    dfs(A);
    cout<<res<<endl;
}
