#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin >> n >> m;
    queue<ll> que;
    ll i;
    vector<ll> v[n];
    ll par[n];
    ll a,b;
    for(i=0;i<n;i++){
        par[i]=-1;
    }
    for(i=0;i<m;i++){
        cin >> a >> b;
        v[a-1].push_back(b);
        v[b-1].push_back(a);
    }
    par[0]=0;
    que.push(1);
    ll t;
    while(!que.empty()){
        t=que.front();
        que.pop();
        for(auto itr=v[t-1].begin();itr!=v[t-1].end();++itr){
            if(par[*itr-1]==-1){
                par[*itr-1]=t;
                que.push(*itr);
            }
        }
    }
    cout << "Yes"<<endl;
    for(i=1;i<n;i++){
        cout << par[i]<<endl;
    }
    return 0;
}
