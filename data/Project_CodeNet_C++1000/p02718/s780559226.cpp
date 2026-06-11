#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

void solve(){
    int m,n;
    cin >> n>>m;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());

    int tot = 0;
    for(int i : a) tot += i;
    if(4*m*a[m-1] >= tot){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}