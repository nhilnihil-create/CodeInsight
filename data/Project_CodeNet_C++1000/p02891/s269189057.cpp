# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
string s;
ll k;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>s;
    cin>>k;
    ll cnt=0;
    ll ans=0;
    char PREV=s[0];
    bool udh=false;
    int x;
    for(auto isi:s){
        if(isi==PREV){
            cnt++;
        }
        else{
            if(udh==false){
                x=cnt;
                udh=1;
            }
            ans+=cnt/2;
            cnt=1;
        }
        PREV=isi;
    }  
    if(udh==false){
        cout<<cnt*k/2<<endl;
        return 0;
    }
    bool u=false;
    ans+=cnt/2;
    if(s.back()==s[0] && x&1 && cnt&1){
        u=true;
    }
    ans=ans*k;
    if(u) ans+=(k-1);
    cout<<ans<<endl;
}
/*
aaaaaaaabbbbbbaaaaa
100
*/