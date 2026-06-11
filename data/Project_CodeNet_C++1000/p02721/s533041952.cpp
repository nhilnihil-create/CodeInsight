#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

int n,k,c;
string s;

set<int> greed(bool flip){
    set<int> ans;
    int last = -c;
    for(int i = 0; i < n; ++i){
        if(s[i]=='o' && i-last>=c){
            last = i;
            if(!flip) ans.insert(i);
            else ans.insert(n-1-i);
        }
    }
    return ans;
}

void solve(){
    cin>>n>>k>>c>>s;
    ++c;
    set<int> s1 = greed(false); 
    if((int)s1.size()==k){
        reverse(s.begin(), s.end());
        set<int> s2 = greed(true);
        for(int i : s1){
            if(s2.count(i)){
                cout << i+1 << "\n";
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}