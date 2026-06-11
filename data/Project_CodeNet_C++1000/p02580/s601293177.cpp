#include<iostream>
#include<vector>
#include<string>
#include <queue>
#include<map>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include<set>

using namespace std;
#define _USE_MATH_DEFINES
# define M_PI 3.14159265358979323846
# define MOD 1000000007
#define ll long long int
#define pii pair<ll, ll>
#define pb push_back
#define MIN -9,223,372,036,854,775
#define N 100005
#define all(v) v.begin(),v.end()

void solve(){
    ll i,j,k,n,ans=0,m,mx=0,my=0,a,b,x,y;
    cin>>n>>m>>k;
    set<pii> s;
    unordered_map<ll, ll> tx,ty;
    vector<ll> vx,vy;
    for(i=0;i<k;i++){
        cin>>a>>b;
        s.insert({a,b});
        tx[a]++;
        ty[b]++;
        if( tx[a]>mx ){
            vx.clear();
            mx=tx[a];
            vx.push_back(a);
        }
        else if(tx[a]==mx){
            vx.push_back(a);
        }
        
        if( ty[b]>my ){
            my=ty[b];
            vy.clear();
            vy.push_back(b);
        }
        else if(ty[b]==my){
            vy.push_back(b);
        }
    }

    if(k<=2){
        cout<<k;
        return;
    }
    ans=mx+my;
    ll f=0;
    for(i=0;i<vx.size();i++){
        for(j=0;j<vy.size();j++){
            if( s.find({vx[i], vy[j]}) == s.end() ){
                f=1;
                break;
            }
        }
    }
    
    if( !f )
        ans--;
    

    cout<<ans;

}

int main() {
    ll t=1;
	//cin>>t;
	while( t-- ){
	    solve();
	    cout<<"\n";
	}
	return 0;
}

/*
5 5 10
2 5
4 3
2 3
5 5
2 2
5 4
5 3
5 1
3 5
1 4
*/
