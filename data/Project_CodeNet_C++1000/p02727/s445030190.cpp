#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
const int INF = 1000100100;


int main(){
    ll x,y,a,b,c,k=0,p[100005],q[100005],r[100005],sum=0;
    cin>>x>>y>>a>>b>>c;
    rep(i,a){
        cin>>p[i];
    }
    sort(p,p+a, greater< int >());
    rep(i,b){
        cin>>q[i];
    }
    sort(q,q+b, greater< int >());
    rep(i,c){
        cin>>r[i];
    }
    sort(r,r+c, greater< int >());
    x--;
    y--;
    if(x>=0&&y>=0){
        while(p[x]<r[k]||q[y]<r[k]){
            if(p[x]<r[k]&&q[y]<r[k]){
                if(p[x]<q[y]){
                    sum+=r[k];
                    x--;
                    k++;
                }else{
                    sum+=r[k];
                    y--;
                    k++;
                }
            }else if(p[x]<r[k]){
                sum+=r[k];
                x--;
                k++;
            }else if(q[y]<r[k]){
                sum+=r[k];
                y--;
                k++;
            }
            if(x<0||y<0) break;
        }
    }
    if(x>=0){
        while(p[x]<r[k]){
            sum+=r[k];
            x--;
            k++;
            if(x<0) break;
        }
    }
    if(y>=0){
        while(q[y]<r[k]){
            sum+=r[k];
            y--;
            k++;
            if(y<0) break;
        }
    }
    for(int i=x;i>=0;i--){
        sum+=p[i];
    }
    for(int i=y;i>=0;i--){
        sum+=q[i];
    }
    cout<<sum;
}