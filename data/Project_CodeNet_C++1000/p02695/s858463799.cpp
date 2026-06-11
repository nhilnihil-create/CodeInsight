#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans=0;
int n,m,q;

ll calc(vector<vector<int>> &rule, vector<int>A){
    ll result=0;
    for(int i=0; i<q; i++){
        int a,b,c,d;
        a = rule.at(i).at(0);
        b = rule.at(i).at(1);
        c = rule.at(i).at(2);
        d = rule.at(i).at(3);
        if(A.at(b)-A.at(a) == c) result += (ll)d;
    }
    return result;
}

void dfs(vector<vector<int>> &rule, int last, vector<int> A){
    if(A.size() >= n){
        ans = max(ans, calc(rule, A));
        return;
    }
    else{
        for(int i=last; i<=m;i++){
            A.push_back(i);
            /*
            for(int j=0; j<A.size(); j++){
                cout << A.at(j) << " ";
            }
            cout << "s" << A.size();
            cout << endl;
            */
            dfs(rule, i, A);
            A.pop_back();
        }
    }
}

int main(){
    cin >> n >> m >> q;
    vector<vector<int>> rule(q, vector<int>(4));
    for(int i=0; i<q; i++){
        cin>>rule.at(i).at(0)>>rule.at(i).at(1)>>rule.at(i).at(2)>>rule.at(i).at(3);
        rule.at(i).at(0)--;
        rule.at(i).at(1)--;
    }
    for(int i=1; i<=m; i++){
        vector<int> A(0);
        A.push_back(i);
        dfs(rule, i, A);
    }
    cout << ans << endl;
}