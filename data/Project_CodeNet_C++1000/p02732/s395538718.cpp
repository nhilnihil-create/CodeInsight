#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int N; vi A; map<int,int> M;
void input()
{
    cin>>N;
    for(int i=0;i<N;++i){
        int a; cin>>a; A.emplace_back(a);
    }
}

void solve()
{
    ll ans=0;
    for(auto i:A){
        ans+=(ll)M[i]++;
    } 
    
    // for(auto m:M) ans+=m.second*(m.second-1)/2;
    for(int i=0;i<N;++i){
        cout<<ans-(ll)(M[A[i]]-1)<<endl;
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