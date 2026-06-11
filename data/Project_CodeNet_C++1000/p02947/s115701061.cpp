# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
int n;
string s;
unordered_set<string>SET;
unordered_map<string,ll>byk;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        sort(s.begin(),s.end());
        SET.insert(s);
        byk[s]++;
    }
    ll ans=0;
    for(string isi:SET){
        ans+=(byk[isi]*(byk[isi]-1))/2;
    }
    cout<<ans<<endl;
}