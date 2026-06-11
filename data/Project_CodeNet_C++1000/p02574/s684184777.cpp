#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

const int MAX = 1e6 + 5;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> cnt(MAX);
    rep(i,n) cnt[a[i]]++;
    int p = 1;
    for(int i = 2; i < MAX; i++){
        int tmp = 0;
        for(int j = i; j < MAX; j += i){
            tmp += cnt[j];
        }
        p = max(tmp, p);
    }
    if(p == 1){
        cout << "pairwise coprime" << endl;
    }else if(p < n){
        cout << "setwise coprime" << endl;
    }else{
        cout << "not coprime" << endl;
    }
}