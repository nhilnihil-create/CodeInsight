#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int N; map<int,int> M;
void input()
{
    cin>>N;
    for(int i=0; i<N-1; ++i){
        int a; cin>>a; M[a]++;
    }
}

void solve()
{
    for(int i=1;i<=N;++i){
        cout<<M[i]<<endl;
    }
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}