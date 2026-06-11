#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    vector<int> b = a;
    sort(b.begin(),b.end(),greater<int>());
    int first_v = b.at(0);
    int second_v = b.at(1);
    rep(i,n){
        if(a.at(i) == first_v){
            cout << second_v << endl;
            continue;
        }
        cout << first_v << endl;
    }
}