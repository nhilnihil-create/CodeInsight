#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define SIZE(x) ll(x.size())

#define INF 1000000000000 //10^12
#define MOD 1000000007 //10^9+7:合同式の法


int main(){
    ll h,w;
    cin >> h >> w;

    if(h==1 || w==1){
        cout << 1 << endl;
        return 0;
    }
    if(h%2==0 && w%2==0){
        cout << h*w/2 << endl;
        return 0;
    }
    else if(h%2==0 && w%2!=0){
        cout << h*(w-1)/2 + h/2 << endl;
        return 0;
    }
    else if(h%2!=0 && w%2==0){
        cout << (h-1)*w/2 + w/2 << endl;
        return 0;
    }
    else if(h%2!=0 && w%2!=0){
        cout << (h*w+1)/2 << endl;
        return 0;
    }
    //return 0;
}