#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using Vec = vector<int>;
using Graph = vector<vector<int>>;
int main(){

ll n;
cin>>n;
int count=1;
while(n>1){
    n/=2;
    count++;
}
ll ans=0;
ll x=1;
for(int i=0;i<count;i++){
    ans+=x;
    x*=2;
}
cout<<ans<<endl;

}