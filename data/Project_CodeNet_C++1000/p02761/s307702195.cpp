#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn = 1000000;
ll mod = INF;

int ans=0;
int a[3]={-1,-1,-1};
int n,m;
int M=0;

int main(){
    cin >> n>>m;
    rep(i,m){
        int s,c;
        cin >> s>>c;
        if(n<s){
            cout << -1<<endl;
            return 0;
        }
        
        if(a[n-s]==-1){
            a[n-s]=c;
        }else if(a[n-s]!=INF&&a[n-s]!=c){
            cout << -1<<endl;
            return 0;
        }
    }

    if(n==1){
        for(int i=0;i<=9;i++){
            bool key=true;
            int tmp=i;
            for(int j=0;j<n;j++){
                if(a[j]!=-1&&a[j]!=tmp%10){
                    key=false;
                    break;
                }
                tmp=tmp/10;
            }
            if(key){
                cout << i<<endl;
                return 0;
            }
        }
    }else if(n==2){
        if(a[n-1]==0){
            cout << -1<<endl;
            return 0;
        }
        for(int i=10;i<=99;i++){
            bool key=true;
            int tmp=i;
            for(int j=0;j<n;j++){
                if(a[j]!=-1&&a[j]!=tmp%10){
                    key=false;
                    break;
                }
                tmp=tmp/10;
            }
            if(key){
                cout << i<<endl;
                return 0;
            }
        }
    }else{
        if(a[n-1]==0){
            cout << -1<<endl;
            return 0;
        }
        for(int i=100;i<=999;i++){
            bool key=true;
            int tmp=i;
            for(int j=0;j<n;j++){
                if(a[j]!=-1&&a[j]!=tmp%10){
                    key=false;
                    break;
                }
                tmp=tmp/10;
            }
            if(key){
                cout << i<<endl;
                return 0;
            }
        }
    }

    //cout << -1<<endl;
    return 0;
}