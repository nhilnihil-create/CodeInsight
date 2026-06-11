#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef  long long ll;
typedef  unsigned long long ull;

template<typename T>
void fin (T a){
    cout<<a<<endl;
    exit(0);
}

template<typename S>
void print(S a){
    cout<<a<<endl;
}

template<typename U>
void pprint(U a){
    cout<<a<<" ";
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s,t;
    cin >> s>>t;

    int ans = t.size();
    for (int i = 0; i <= s.size() - t.size(); i++) {
        int diff = 0;
        rep(k,t.size()){
            if(s[i+k] != t[k]){
                diff++;
            }
        }
        ans = min(diff,ans);
    }

    fin(ans);
    return 0;
}


