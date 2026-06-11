// 今日はお盆前の最終出社日です
// いい加減寝ろ

#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};

/*

型を使いたいように合わせる！！！！！！！！！！！！！！！！！！！！！！！！！！！！

*/
bool comp(pair<ll, ll> a, pair<ll , ll> b) {
    // 基本はfirstで比較
    if(a.first != b.first){
         return a.first < b.first; // 昇順
        //return a.first > b.first; // 降順
    }

    // それ以外はsecondで比較
    if(a.second != b.second){
        return a.second > b.second;
    }else{
        // どちらも同じ
        return true;
    }
}
int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll a,b,c,d,maxi=0,f=0,mini=INF,sum=0;
    ll n;
    ll k;
    cin>>n>>a>>d;
    vector<pair<ll,ll>> p(n);
        //vector<pair<ll,ll>> pa(n);
    map<ll,ll> m;
    rep(i,n){
        cin>>c>>b;
        p[i]=make_pair(c,b);
    }
    sort(all(p),comp);
    //lastexplosionが範囲に入っていた時のダメージが入っている
    ll lastd=0;
    //lastexplosionの影響範囲が入っている
    ll lastx=-1;
    ll bombs=0;
    ll lastfirst=0;
    deque<pair<ll,ll>> dq;
    rep(i,n){
        while(!dq.empty()&&dq.front().first<p[i].first){
            bombs-=dq.front().second;
            dq.pop_front();
        }
        //if(lastd>=p[i].second) continue;
        if(!dq.empty()&&dq.front().first>=p[i].first&&bombs*d>=p[i].second) continue;
        //まえの爆発の影響範囲内の時
        if(!dq.empty()&&dq.front().first>=p[i].first){
            //cout<<"hanni nai";
            ll lastbomb=bombs;
            bombs+=(p[i].second-bombs*d)/d;
            if(((p[i].second-bombs*d)%d)!=0) bombs++;
            sum+=bombs-lastbomb;
            pair <ll,ll> pa;
            pa=make_pair(p[i].first+a*2,bombs-lastbomb);
            dq.push_back(pa);
        }else{
        //まえの爆発の影響範囲外の時
            ll lastbomb=bombs;
            bombs+=(p[i].second)/d;
            if((p[i].second%d)!=0) bombs++;
            sum+=bombs-lastbomb;
            pair <ll,ll> pa;

            pa=make_pair(p[i].first+a*2,bombs-lastbomb);
            dq.push_back(pa);
        }
        //cout<<i<<" "<<sum<<endl;
        //while(i<n-1&&p[i].first==p[i+1].first) i++;
        //lastx=p[i].first+a*2;
        
    }
    cout<<sum<<endl;


    return 0;
}
