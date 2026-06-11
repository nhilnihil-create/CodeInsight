#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<queue>
#include<map>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int n,k,c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    vector<int> l(n),r(n);
    int cur=1;
    for(int i=0;i<n;i++){
        if(s[i]=='x') continue;
        l[i] = cur;
        i += c;
        cur++;
    }
    cur = k;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='x') continue;
        r[i] = cur;
        i -= c;
        cur--;
    }

    vector<int> ans(n);
    for(int i=0;i<n;i++){
        if(l[i]!=0 && l[i]==r[i]){
            ans[i] = i+1;
        }
    }

    for(int i=0;i<n;i++){
        if(!ans[i]) continue;
        cout << ans[i] << endl;
    }
}