#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
using namespace std;
using ll = long long;

vector<int> sho(vector<int> &p){
    int nm = log2(p.size());
    int m = pow(2,nm);
    vector<int> ans(p.size() - m + 1);
    vector<vector<int>> rui(p.size() + 1, vector<int>(2));
    rui[0][0] = 0;
    rui[0][1] = 0;
    repp(j,p.size() + 1,1){
        if (p[j-1] == 1){
            rui[j][0] = rui[j-1][0] + 1;
            rui[j][1] = rui[j-1][1];
        }
        else if (p[j-1] == 2){
            rui[j][1] = rui[j-1][1] + 1;
            rui[j][0] = rui[j-1][0];
        }
        else{
            rui[j][0] = rui[j-1][0];
            rui[j][1] = rui[j-1][1];
        }
    }
    rep(i,ans.size()){
        if (rui[i+m][0] - rui[i][0] == 0){
            if ((rui[i+m][1] - rui[i][1]) % 2 == 1){
                ans[i] = 2;
            }
            else{
                ans[i] = 0;
            }
        }
        else if ((rui[i+m][0] - rui[i][0]) % 2 == 1){
            ans[i] = 1;
        }
        else{
            ans[i] = 0;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> bit(n);
    string s;
    cin >> s;
    int a;
    string ss;
    rep(i,n){
        ss = s.at(i);
        a = atoi(ss.c_str());
        bit[i] = a-1;
    }
    vector<int> nans = bit;
    while (nans.size() > 1){
        nans = sho(nans);
    }
    cout << nans[0] << endl;
}