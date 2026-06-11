#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int N;
    ll K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N){
        cin>> A[i];
        A[i]--;
    }

    deque<int> a;
    vector<bool> seen(N, false);
    int cur = 0;

    while(true){
        if(seen[cur]){
            while(a[0] != cur){
                K--;
                a.pop_front();

                if(K == 0){
                    cout<< a[0] + 1 << endl;
                    return 0;
                }
            }
            break;
        }
        a.push_back(cur);
        seen[cur] = true;
        cur = A[cur];
    }
    cout<< a[K % a.size()] + 1 << endl;
}
