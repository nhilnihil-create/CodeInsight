#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int N,M; vi A;
void input()
{
    cin>>N>>M;
    for(int i=0;i<M;++i){
        int a; cin>>a; A.emplace_back(a);
    }
}

void solve()
{
    int sum=0;
    for(int i=0;i<M;++i){
        sum+=A[i];
        if(sum>N){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<N-sum<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}