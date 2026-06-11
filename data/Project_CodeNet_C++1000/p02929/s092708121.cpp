#include <iostream>
#include<iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define NO cout<<"NO"<<endl;
#define YES cout<< "YES"<<endl;
#define No cout<< "No"<<endl;
#define Yes cout<< "Yes"<<endl;
#define all(a) a.begin(),a.end()
#define P pair<int,int>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//(int)'a'は97 (int)'A'は65 (int)'1'は49
//おまじない

const int maxn = 100000;

int main(){
    
    ll n;
    ll ans=1;
    ll mod = INF;
    
    ll r=0;
    bool d[2*maxn]={0};
    string s;
    cin >> n;
    cin >> s;
    
    if(s[0]=='W'||s[2*n-1]=='W'){
        cout << 0<<endl;
    }else{
        //L=false,R=true
        d[0]=false;
        d[2*n-1]=true;
        rep(i,2*n-1){
            if(s[i]==s[i-1]){
                if(d[i-1])d[i]=false;
                else d[i]=true;
            }else{
                if(d[i-1])d[i]=true;
                else d[i]=false;
            }
        }
        rep(i,2*n){
            if(d[i])r++;
        }
        if(r!=n){
            cout << 0<<endl;
        }else{
            ll pl=0;
            ll pr=0;
            ll rr=r;
            rep(i,s.size()){
                if(d[i]){
                    ans=(ans*(pl-pr))%mod;
                    rr--;
                    pr++;
                }else{
                    pl++;
                }
            }
            for(ll i=1;i<=n;i++){
                ans=(ans*i)%mod;
            }
            cout << ans<<endl;
        }
    }
    
    
    return 0;
}

