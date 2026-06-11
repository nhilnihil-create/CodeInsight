#include <bits/stdc++.h>
#define ref(i,n) for (int i=0;i<n;i++)
using namespace std;
typedef long long ll;
int n;
ll a[201];
ll v2(ll x){
    ll k=-1;
    while(x){
        k++;
        x/=2;
    }
    return k;
}

int main()
{
    cin>>n;
    ref(i,n){
        int t;
        cin>>t;
        ref(i,t) cin>>a[i];
        string s;
        cin>>s;
        set<ll> v,vv,vk;
        ll k=0;bool rr=1;
        for(int i=t-1;i>=0;i--){

            if(s[i]=='0') v.insert(a[i]);
            else{
                    //cout<<s[i];
                bool r=0;
                while(v.size()){
                        auto it=v.begin();
                        v.erase(v.begin());
                    ll x=*it;

                    auto ii=vv.end();auto ik=vk.end();
                        bool used=0;
                        for(int j=vv.size()-1;j>=0;j--){
                                ii--;ik--;

                            ll q=v2(x);

                            if(*ik>q) continue;
                            if(*ik==q) x=x^*ii;
                            if(*ik<q){
                                vk.insert(q);
                                vv.insert(x);
                                used=1;
                                break;
                            }
                        }
                        it++;
                        if(!used&&x) {
                            vv.insert(x);
                            vk.insert(v2(x));
                        }
                }
                auto ii=vv.end();auto ik=vk.end();
                for(int j=vv.size()-1;j>=0;j--){
                        ii--;ik--;
                    if(a[i]>>*ik) a[i]^=*ii;

                    if(!a[i]) {r=1;break;}
                }
                if(r==0) {cout<<1<<endl; rr=0;break;}

            }

            }
            if(rr) cout<<0<<endl;
        }
     return 0;
    }

