#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n;
    ll k;
    cin>>n>>k;
    vector<int> A(n);
    rep(i,n){
        cin>>A[i];
        A[i]--;
    }

    vector<bool> seen(n,false);
    deque<int> a;
    int cur=0;
    while(true){
        if(seen[cur]){
            while(a[0]!=cur){
                k--;
                a.pop_front();

                if(k==0){
                    cout<<a[0]+1<<endl;
                    return 0;
                }
            }
            break;
        }

        a.push_back(cur);
        seen[cur]=true;
        cur=A[cur];
    }
    cout<<a[k%a.size()]+1<<endl;
}