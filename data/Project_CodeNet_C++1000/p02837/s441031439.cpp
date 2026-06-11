#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;

int main() {
    int N; cin>>N;
    vi A(N);
    vector<vi> x(N);
    vector<vector<bool>> y(N);
    for (int i = 0; i < N; i++){
        cin>>A[i];
        for (int j = 0; j < A[i]; j++){
            int a,b; cin>>a>>b; a--;
            x[i].push_back(a);
            y[i].push_back(b);
        }
    }
    int ans=0;
    for (int i = 0; i < (1<<N); i++){
        bitset<15> b(i);
        bool ng=false;
        for (int j = 0; j < N; j++){
            if(b[j]){
                for (int k = 0; k < A[j]; k++){
                    if(b[x[j][k]]!=y[j][k])ng=true;
                }
            }
            if(ng)break;
        }
        if(!ng){
            ans=max(ans,(int)b.count());
        }
    }
    cout<<ans<<endl;
}