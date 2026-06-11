#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <stack>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

vector<int> E[26];
ll N,M;
map<int,vector<int>> m;
string s,t;
bool found = true;
ll ans = 0;
vector<int>::iterator position;
vector<int> e;


 
 
int main(){
    cin >> s >> t;
    N = s.size();
    M = t.size();
    for(int i=0;i<N;i++){
        int a = s[i] -'a';
        E[a].push_back(i);
    }
    ll j=-1;
    for(int i=0;i<M;i++){
        int b = t[i] -'a';
        if(E[b].empty()){
            found = false;
            break;
        }
        position = upper_bound(E[b].begin(), E[b].end(), j);
        ll k = *position;
        if(position== E[b].end()){
            k = E[b][0];
            ans+=1;
        }
        j = k;
    }
    ans = ans*N + j+1;
    if(found){
      cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
    
}
