//c++ テンプレ
#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


void solve(){
    string s;
    cin >> s;
    int n=s.size();
    vector<int>ans(n);
    for(int j=0;j<2;j++){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='R')cnt++;
            else{
                ans[i]+=cnt/2;
                ans[i-1]+=(cnt+1)/2;
                cnt=0;
            }
        }
    
        reverse(ans.begin(), ans.end());
        reverse(s.begin(), s.end());
        for(int i=0;i<n;i++){
            if(s[i] == 'L') s[i] = 'R';
        else s[i] = 'L';
        }
    }
    for(int i=0;i<n;i++)cout << ans[i] << " ";
    cout << endl;
}

int main(){
  solve();
  return 0;
}
