// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで

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

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,d,m,n,maxi=0,f=0,mini=INF,sum=0;
    string str;
    cin>>n;
    //vector<vector<ll>> v(tate,vector<ll> (yoko));
    vector<ll> v(n);
    rep(i,n+1)   cin >> v[i];
    sort(all(v));
    ll pf=0;
    ll mf=0;
    rep(i,n){
        if(v[i]<0) mf++;
        if(v[i]>0) pf++;
    }
    rep(i,n) sum+=abs(v[i]);
    if(pf==0) {
        sort(rall(v));
        sum-=abs(v[0]*2);
    }
    if(mf==0) {
        sum-=abs(v[0]*2);
    }
    cout<<sum<<endl;
    if(n==2){
        if(mf=0){
            cout<<v[1]<<" "<<abs(v[0])<<endl;
        }else if(pf==0){
            cout<<v[0]<<" "<<abs(v[1])<<endl;
        }else{
            cout<<v[1]<<" "<<abs(v[0])<<endl;
        }
        return 0;
    }
    if(pf==1){
        sort(rall(v));
        rep(i,n-1){
            cout<<v[i]<<" "<<v[i+1]<<endl;
            v[i+1]=v[i]-v[i+1];
        }
        return 0;
    }
    if(mf==1){
        rep(i,n-2){
            cout<<v[i]<<" "<<v[i+1]<<endl;
            v[i+1]=v[i]-v[i+1];
        }
            cout<<v[n-1]<<" "<<v[n-2]<<endl;

        return 0;
    }


    if(mf==0){
        rep(i,n-2){
        cout<<v[i]<<" "<<v[i+1]<<endl;
        v[i+1]=v[i]-v[i+1];
        }
        cout<<v[n-1]<<" "<<v[n-2]<<endl;
    }else if(pf==0){
        //cout<<"hoi";
        rep(i,n-1){
        cout<<v[i]<<" "<<v[i+1]<<endl;
        v[i+1]=v[i]-v[i+1];
        }
    }else{
        //最大値をとっておく
        sort(rall(v));
        ll plus = v[0];
        v.erase(v.begin());
        //最大値の次に来るマイナスをとる
        sort(all(v));
        //cout<<v[0]<<endl;
        a=v[0];
        v.erase(v.begin());
                //cout<<"size: "<<v.size()<<endl;

        //降順
        sort(rall(v));
        cout<<a<<" "<<v[0]<<endl;
        v[0]=a-v[0];
        //rep(i,v.size()) cout<<v[i]<<" ";
        ll st;
        n=v.size();
        rep(i,n-1){
            cout<<v[i]<<" "<<v[i+1]<<endl;
            v[i+1]=v[i]-v[i+1];
            st=i+1;
            if(v[i+2]<0) break;
        }
        cout<<plus<<" "<<v[st]<<endl;
        v[st]=plus-v[st];
        n=v.size();
        REP(i,st,n-1){
            //cout<<"i; "<<i<<endl;
            cout<<v[i]<<" "<<v[i+1]<<endl;
            v[i+1]=v[i]-v[i+1];
        }
        //cout<<plus<<" "<<v[v.size()-1]<<endl;
    }
    return 0;
}
