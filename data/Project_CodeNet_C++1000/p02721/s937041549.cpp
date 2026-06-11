#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=acos(-1);
const ll MOD=1e9+7;
const ll INF=(1LL<<60);

int main() {
    ll n,k,c;
    string s;
    cin>>n>>k>>c;
    cin>>s;
    int d[n+2];
    d[n+1]=0;
    for (int i=0;i<c+1;i++){
        if (s[n-1-i]=='o')d[n-i]=1;
        else d[n-i]=max(0,d[n-i+1]);
    }
    for (int i=n-c-1;i>0;i--){
        if (s[i-1]=='o')d[i]=1+d[i+c+1];
        else d[i]=d[i+1];
    }
    //for (int i=1;i<n+1;i++)cout<<d[i]<<endl;
    vector<int> dic;
    rep(i,n){
        if (s[i]=='o')dic.push_back(i+1);
    }
    vector<int> dic2;//答えの候補
    int now=dic[0];
    dic2.push_back(now);
    while (dic2.size()<k){
        int index=dic2.size();
        int num=dic2[index-1];
        int index1=lower_bound(all(dic),num+1+c)-dic.begin();
        dic2.push_back(dic[index1]);
        //cout<<dic2[index]<<endl;
    }
    vi ans;
    rep(i,k){
        int num=dic2[i];
        if (i+d[num+1]>=k)continue;
        else ans.push_back(num);
    }
    for (int x:ans)cout<<x<<endl;


    return 0;
}