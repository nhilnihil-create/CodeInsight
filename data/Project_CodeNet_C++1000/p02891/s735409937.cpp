#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define USE_LLONG_AS_INT
#ifdef USE_LLONG_AS_INT
#define int long long
#define inf (1ll<<60)
#else
#define inf (1<<30)
#endif
#define rep(i,n) for(int i=0;i<(n);i++)
#define Rep(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define rev(i,n) for(int i=(n)-1;i>=0;i--)
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define eb emplace_back
#define pi pair<int,int>
#define vp vector<pair<int,int>>
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define MEMSET(a) memset(a,0,sizeof(a))
#define Yes(f) cout<<(f?"Yes":"No")<<endl
#define yes(f) cout<<(f?"yes":"no")<<endl
#define YES(f) cout<<(f?"YES":"NO")<<endl
#define SORT(v) sort(all(v))
#define RSORT(v) sort(all(v), greater<int>())

using namespace std;

const int mod=1e9+7;
const string sp=" ";

void run();

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
}

signed main(){
    init();
    run();
    return 0;
}

void run(){
    string s;
    int k;
    cin>>s>>k;
    string t=s;
    t.erase(unique(all(t)),t.end());
    if(t.length()==1){
        cout<<s.length()*k/2<<endl;
        return;
    }
    int n=s.length();
    int ans=0;
    int cnt=1;
    Rep(i,1,n){
        if(s[i]!=s[i-1]){
            ans+=cnt/2;
            cnt=1;
        }
        else cnt++;
    }
    ans+=cnt/2;
    ans*=k;
    if(s[0]==s[s.length()-1]){
        int a=1;
        for(int i=0;s[i]==s[i+1];i++,a++);
        int b=1;
        for(int i=n-1;s[i]==s[i-1];i--,b++);
        ans-=(a/2+b/2-(a+b)/2)*(k-1);
    }
    cout<<ans<<endl;
    
}