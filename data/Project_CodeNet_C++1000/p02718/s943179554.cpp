#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int M,N; vi A;
void input()
{
    cin>>N>>M;
    for(int i=0;i<N;++i){
        int a;cin>>a;A.emplace_back(a);
    }
}

void solve()
{
    sort(A.begin(),A.end(),greater<int>());
    int sum=0;
    for(int i=0;i<N;++i) sum+=A[i];
    if(A[M-1]*4*M>=sum) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}