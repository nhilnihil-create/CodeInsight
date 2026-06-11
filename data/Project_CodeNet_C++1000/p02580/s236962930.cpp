#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define inf 100000000000000000
#define mod 1000000007
#define MAX 300005
#define pb push_back
#define mp make_pair
#define vit vector<int>::iterator
typedef pair<lint,lint> pii;
map<pii,lint> MP;
lint X[MAX],Y[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    lint H,W,M,mx=0,my=0,a,b;
    cin>>H>>W>>M;
    for(lint i=1;i<=M;i++){
        cin>>a>>b;
        MP[mp(a,b)]=1;
        X[a]++;
        Y[b]++;
    }
    for(lint i=1;i<=H;i++) mx=max(mx,X[i]);
    for(lint i=1;i<=W;i++) my=max(my,Y[i]);
    lint ans=mx+my-1;
    vector<lint> xx,yy;
    for(lint i=1;i<=H;i++){
        if(X[i]==mx){
            xx.pb(i);
        }
    }
    for(lint i=1;i<=W;i++){
        if(Y[i]==my){
            yy.pb(i);
        }
    }
    for(auto u:xx){
        for(auto v:yy){
            if(!MP[mp(u,v)]){
                cout<<ans+1;
                return 0;
            }
        }
    }
    cout<<ans;
    return 0;
}
