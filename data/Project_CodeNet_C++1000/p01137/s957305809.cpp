#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define REAP(i,a,n) for(int i=(a);i<(n);i++)
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
#define fr first
#define sc second
#define pb push_back
#define All(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll e;
    while(cin >> e,e){
        ll m=e;
        for(int y=0;y*y<=e;y++){
            for(int z=0;z*z*z+y*y<=e;z++){
                m=min(m,y+z+(e-y*y-z*z*z));
            }
        }
        cout << m << endl;
    }
}

