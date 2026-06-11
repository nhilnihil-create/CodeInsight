#include<bits/stdc++.h>
using namespace std;

class Takoyaki{
private:
    int n,x,t;
public:
    Takoyaki(){
        cin>>n>>x>>t;
    }
    int solve(){
        int ans = ceil((float)n/x)*t;
        return ans;
    }
};

int main(){
    Takoyaki problem = Takoyaki();
    int ans = problem.solve();
    cout<<ans<<"\n";
}