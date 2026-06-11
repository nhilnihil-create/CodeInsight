#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int n, k, c;

vector<int> sub(string s){
    int n = s.size();
    int cur = 0; 
    int last = - c - 1;
    vector<int> res(n+1, 0);
    for(int i = 0; i < n; i++){
        if(i > last + c && s[i] == 'o') ++cur, last = i;
        res[i+1] = cur;
    }
    return res;
}

int main(){
    cin >> n >> k >> c;
    string s; cin >> s;
    auto left = sub(s);
    string t = s;
    reverse(ALL(t));
    auto right = sub(t);
    for(int i = 0; i < n; i++){
        if(s[i] == 'x') continue;
        if(left[i] + right[n-i-1] < k) cout << i+1 << endl;
    }
}