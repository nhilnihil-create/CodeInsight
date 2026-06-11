#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(void){
    string s;
    cin>>s;
    int n = (int)s.size()+1;
    
    vi a(n, 0);
    
    for(int i=0; i<n-1; i++){
        if(s[i]=='<')
            a[i+1] = max(a[i+1], a[i]+1);
    }
    for(int i=n-2; i>=0; i--){
        if(s[i]=='>'){
            a[i] = max(a[i], a[i+1]+1);
        }
    }
    
    cout << accumulate(a.begin(), a.end(), ll(0)) << endl;
    return 0;
}
