#include<bits/stdc++.h>
using namespace std;

class Step{
private:
    int n;
    vector<int> A;
public:
    Step(){
        cin>>n;
        A.resize(n,0);
        for(int i=0; i<n; ++i) cin>>A[i];
    }
    long long solve(){
        int mx = A[0];
        long long ans=0;
        for(int i=1; i<n; ++i){
            ans+=max(0, mx-A[i]);
            mx = max(mx,A[i]);
        }
        return ans;
    }
};

int main(){
    Step problem;
    long long ans = problem.solve();
    cout<<ans<<'\n';
}