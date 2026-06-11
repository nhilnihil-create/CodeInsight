#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
#define INF 100000000
#define MAX 200001
#define MOD 1000000009
ll fac[MAX],finv[MAX],inv[MAX];
typedef vector<vector<int> > Graph;
const int m=2019;

int main(){
    string s;cin>>s;
    int n=s.size();
    reverse(s.begin(),s.end());
    int x=1,tot=0;
    vector<int> cnt(m);
    ll ans=0;
    for(int i=0;i<n;i++){
        cnt[tot]++;
        tot+=(s[i]-'0')*x;
        tot%=m;
        ans+=cnt[tot];
        x=x*10%m;
    }
    cout<<ans<<endl;
}