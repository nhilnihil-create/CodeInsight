#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional> //operator[]
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

vector<int> Zalgo(string s){
    long n = s.size();
    vector<int> a(n);
    int i=1,j=0;
    while(i<s.size()){
        while(i+j<s.size() && s[j]==s[i+j]) ++j;
        a[i] = j;
        if(j==0){ ++i; continue; }
        int k=1;
        while(i+k<s.size() && k+a[k]<j){
            a[i+k]=a[k];
            k++;
        }
        i+=k;
        j-=k;
    }
    return a;
}
signed main(){
    int n; cin >> n;
    string s; cin >> s;
    int out=0;
    rep(i,n){
        string sub=s.substr(i);
        vector<int> ans=Zalgo(sub);
        rep(j,ans.size()){
            if(j==0) continue;
            chmax(out,min(ans[j],j));
        }
    }
    cout << out << endl;
}
