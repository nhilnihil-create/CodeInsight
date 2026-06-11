#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;

int main() {
    int N; cin>>N;
    vi ans(N);
    for (int i = 0; i < N; i++){
        int a; cin>>a;
        ans[a-1]=i+1;
    }
    for(int x : ans)cout<<x<<" ";
    cout<<endl;
}