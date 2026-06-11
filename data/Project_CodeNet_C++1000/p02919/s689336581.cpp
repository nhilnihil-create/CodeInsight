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
#include <set>
#define ll long long

using namespace std;

long long MOD = 1000000007;

int main(){
    int N;
    cin >> N;
    vector<ll> pos(N,0);
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        x--;
        pos[x]=i;
    }

    set<int> s;
    s.insert(-1);
    s.insert(N);
    ll ans=0;
    for(int i=0; i<N; i++){
        ll p=pos[N-i-1];
        s.insert(pos[N-i-1]);
        if(i>0){
            ll a,b,c,d;
            a=b=MOD;
            c=d=0;
            auto it=s.find(p);
            b=*(--it);
            if(it!=s.begin()){
                a=*(--it);
            }
            it=s.find(pos[N-i-1]);
            c=*(++it);
            ++it;
            if(it!=s.end()){
                d=*it;
            }
            ans+=max(0LL,(b-a)*(c-p)*(N-i))+max(0LL,(p-b)*(d-c)*(N-i));
            //cout << N-i << endl;
            //cout << a << ' ' << b << ' ' << p << ' ' << c << ' ' << d << endl;
        }
    }
    cout << ans << endl;
}