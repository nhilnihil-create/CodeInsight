#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n); i++) 
#define dunk(n) cout << n << endl
#define all(a) (a).begin(),(a).end()
typedef pair<int,int> P;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    if(s.size()%2 == 0){
        rep(i,s.size()/2){
            if(s[s.size()/2-1-i] != s[s.size()/2+i]){
                ans++;
            }
        }
    }
    else{
        rrep(i,s.size()/2+1){
            if(s[s.size()/2-i] != s[s.size()/2+i]){
                ans++;
            }
        }
    }
    dunk(ans);
    return 0;
}