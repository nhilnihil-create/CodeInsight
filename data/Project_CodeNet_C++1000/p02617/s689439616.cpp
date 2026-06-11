#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

int main(){
    ll N;
    cin >> N;
    ll ans=1;
    for(ll i=1; i<N; i++){
        ll u, v;
        cin >> u >> v;
        if(u>v){
            ll tmp=u;
            u=v;
            v=tmp;
        }
        ans-=u*(N-v+1);
        ans+=(N-i+1)*(i+N)/2+(N-i+1)*(1-i);
    }
    cout << ans << endl;
}