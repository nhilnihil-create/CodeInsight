#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX=1e6+1;

int main(){
    int N;
    cin >> N;

    int A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    sort(A, A+N);

    vector<int> div(MAX, 0);
    int num_pre=0;
    rep(i, N){
        if(num_pre==A[i]){
            div[A[i]]=1;
            continue;
        }
        for(int j=A[i]*2; j<MAX; j+=A[i]){
            div[j]=1;
        }
        num_pre=A[i];
    }

    int ans=0;
    rep(i, N){
        if(div[A[i]]==0) ans++;
    }
    cout<<ans<<endl;
    return 0;
}