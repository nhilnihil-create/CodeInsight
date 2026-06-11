#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
    string s;
    cin >> s;
    int n = s.size()+1;
    s='>'+s+'<';
    vector<int> ans(n,-1);
    rep(i,n){
        if(s[i]=='>'&&s[i+1]=='<'){
            ans[i]=0;
            int j = i+1;
            while(j<n+1){
                if(s[j]=='<'){
                    ans[j] = max(ans[j], j-i);
                    j++;
                }
                else break;
            }
            j=i-1;
            while(j>=0){
                if(s[j+1]=='>'){
                    ans[j]= max(ans[j], i-j);
                    j--;
                }
                else break;
            }
        }
    }
    ll sum=0;
    rep(i,n){
        sum += ans[i];
    }
    cout << sum << endl;
    return 0;
}