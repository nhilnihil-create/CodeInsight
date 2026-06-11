#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int N,M,Q;
vector<int> a,b,c,d;


int dfs(vector<int> A){
    if(A.size()==N){
        //得点計算
        int res = 0;
        rep(i,Q){
            if((A.at(b.at(i))-A.at(a.at(i)))==c.at(i)) res += d.at(i);
        }
        return res;
    }

    int prev_last = (A.empty() ? 1 : A.back());
    int ans = 0;
    for(int i = prev_last; i <= M; i++){
        A.push_back(i);
        ans = max(ans,dfs(A));
        A.pop_back();
    }
    return ans;
}

int main(){
    cin>>N>>M>>Q;
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);
    rep(i,Q){
      cin>>a.at(i)>>b.at(i)>>c.at(i)>>d.at(i);
      --a.at(i), --b.at(i);  
    }
    vector<int> A;
    cout << dfs(A) <<endl;
}
