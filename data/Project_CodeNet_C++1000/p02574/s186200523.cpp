#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define mem0(x) memset(x,0,sizeof(x))
#define meminf(x) memset(x,0x3f,sizeof(x))
#define VI vector<int>
#define VL vector<ll>
using namespace  std;

const int N = 1e6+5;
int a[N];
VI prime;int vis[N];
void getprime(){
    rep(i,2,N-5){
        if(!vis[i]){
            prime.push_back(i);
        }
        for(int p:prime){
            int v = p*i;
            if(v>N-5) break;
            vis[v] = 1;
            if(i%p==0) break;
        }
    }
}
set<int> s[N];
int cntt[N];
int main(){
    ios::sync_with_stdio(0);
    getprime();
    int n;cin>>n; int gd;int fg = 1;
    rep(i,1,n){
        cin>>a[i];
        if(i>1&&gd != 1){
            gd = __gcd(gd,a[i]);
        }else if(i==1){
            gd = a[i];
        }
        if(fg&&a[i]!=1){
            
            if(!vis[a[i]]) {
                ++cntt[a[i]];
                if(cntt[a[i]]>1){
                    fg=0;
                }
            }
            else{
                //int lim = sqrt(a[i]+0.5);
                for(int p:prime){
                    //if(lim<p) break;
                    if(a[i]%p==0){
                        ++cntt[p];
                        if(cntt[p]>1){
                            fg=0;break;
                        }
                        if(!vis[a[i]/p]&&cntt[a[i]/p]>1){
                            fg=0;break;
                        }
                    }
                }
            }
            
        }
    }
    if(!fg){
        if(gd==1){
            cout<<"setwise coprime"<<'\n';
        }else{
            cout<<"not coprime"<<'\n';
        }
    }else{
        cout<<"pairwise coprime"<<'\n';
    }


    

    
}
