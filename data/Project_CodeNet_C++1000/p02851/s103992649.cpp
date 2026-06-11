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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N,0);

    map<ll, deque<ll>> s;
    ll ans=0;
    for(int i=0; i<N; i++){
        ll a;
        cin >> a;
        a--;
        a%=K;
        if(i>0){
            A[i]=a+A[i-1];
            A[i]%=K;
        }else{
            A[i]=a;
        }
    }

    s[0].push_back(-1);
    for(int i=0; i<N; i++){
        ll a=A[i];
        if(s.count(a)){
            while((int)s[a].size()>0 && i-s[a].front()>=K){
                s[a].pop_front();
            }
            ans+=(ll) s[a].size();
        }
        s[a].push_back(i);
      	//cout << i << ' ' << A[i] << ' ' << ans <<  endl;
    }

    cout << ans << endl;
}