#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    vector<P> A;
    rep(i,n){
        int a;
        cin >> a;
        A.emplace_back(a,i+1);
    }
    sort(A.begin(),A.end());
    rep(i,n){
        cout << A.at(i).second << " ";
    }
    cout << endl;
}