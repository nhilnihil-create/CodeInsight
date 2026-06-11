#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;

    vector<int> X(N);
    for(int i=0; i<N; i++){
        cin>>X[i];
    }

    sort(X.begin(), X.end());

    int ans = 1e9;
    for(int i=X[0]; i<=X[N-1]; i++){
        int dis = 0;
        
        for(int j=0; j<N; j++){
            dis += (X[j]-i)*(X[j]-i);
        }

        ans = min(dis, ans);
    }

    cout<<ans<<endl;

    return 0;
}