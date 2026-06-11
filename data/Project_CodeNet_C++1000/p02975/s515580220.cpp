#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
#define mod 1000000007
#define pi 3.141592653589793

ll gcd(ll a,ll b){
    if(b>a) swap(a,b);
    ll r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main (){
    ll n;
    map<int,int> mp;
    cin >> n;
    int sum=0;
    rep(i,n){
        ll a;
        cin >> a;
        sum+=a;
        mp[a]++;
    }
    int l=mp.size();
    if(n%3!=0){
        if(sum==0) cout << "Yes" <<endl;
        else cout << "No" <<endl;
    }
    else {
        if(sum==0){
            cout << "Yes" <<endl;
            return 0;
        }
        if(l==2){
            int j=0;
            int x,y;
            int xc,yc;
            for(auto p:mp){
                if(j==0) {
                    x=p.first;xc=p.second;
                }
                else {
                    y=p.second;yc=p.second;
                }
                j++;
            }
            if(x==0&&xc==n/3&&y!=0&&y==2*n/3) cout << "Yes" <<endl;
            else cout << "No" <<endl;
        }
        else if(l==3){
            int j=0;
            int x,y,xy;
            int xc,yc,xyc;
            for(auto p:mp){
                if(j==0){
                    x=p.first;xc=p.second;
                }
                else if(j==1){
                    y=p.first;yc=p.second;
                }
                else {
                    xy=p.first;xyc=p.second;
                }
                j++;
            }
            int z=x^y;
            int xyz=xy^z;
            if(xyz==0&&xc==n/3&&yc==n/3&&xyc==n/3) cout << "Yes" <<endl;
            else cout << "No" <<endl;
        }
        else cout <<"No" <<endl;
    }

    return 0;
}
