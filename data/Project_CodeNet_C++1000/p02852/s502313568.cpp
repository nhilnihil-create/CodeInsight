#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;
typedef pair<ll,ll> P;


int main(){
    ll n,k;cin>>n>>k;
    string s;cin>>s;
    ll now=n;
    vector<ll> an;
    while(1){
        for(ll i=k;i>0;i--){
            if(s[max(now-i,0LL)]=='0'){
                now=now-i;
                if(now<0)an.push_back(now+i);
                else an.push_back(i);
                break;
            }
            
            if(i==1){
                cout<<-1<<endl;
                return 0;
            }
        }
        if(now<=0)break;
    }
    for(ll i=an.size()-1;i>=0;i--){
        cout<<an[i];
        if(i!=0)cout<<" ";
    }
}

    







