#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

void solve()
{
    int N; cin>>N;
    vector<int> a(N);
    for (int i=0;i<N;++i) cin>>a[i];

    vector<int> b(N,0);
    int ans=0;
    for (int i=N-1;i>=0;--i){
        int sum=0;
        for(int j=i+1;j<=N;j+=i+1){
            if(b[j-1]==1) ++sum;
        }
        if(a[i]!=(sum%2)) b[i]=1,++ans;
    }

    cout<<ans<<endl;
    for(int i=0;i<N;++i){
        if(b[i]==1) cout<<i+1<<" ";
    }
    cout<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    // int ti = clock();
    // input();
    solve();
    // printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;
}