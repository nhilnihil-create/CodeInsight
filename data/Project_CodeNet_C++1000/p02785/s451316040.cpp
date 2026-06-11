#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using Vec = vector<int>;
using Graph = vector<vector<int>>;
int main(){

int n,k;
cin>>n>>k;
Vec vec(n);

for(int i=0;i<n;i++){
cin>>vec[i];
}
sort(vec.begin(),vec.end());
vec.erase(vec.end()-k+1, vec.end());
ll ans=0;

for(int i=0;i<n-k;i++){
    ans+=vec[i];
}
cout<<ans<<endl;


}