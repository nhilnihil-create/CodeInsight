#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()


int main() {
    string S;
    cin>>S;
    bool f=true;
    rep(i,0,S.size()){
        ll j=i+1;
        if(S[i]=='R'&&j%2==1)continue;
        else if(S[i]=='L'&&j%2==0)continue;
        else if(S[i]=='U'||S[i]=='D')continue;
        else f=false;
    }
    cout<<(f ? "Yes":"No")<<endl;
    return 0;
}