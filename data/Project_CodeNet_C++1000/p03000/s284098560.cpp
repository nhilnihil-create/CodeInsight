#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
int n,x;
cin>>n>>x;
vector <int> L(n),B;
for(auto &e:L)cin>>e;
int d=0;
B.emplace_back(d);
for(int i=0;i<n;i++){
    B.emplace_back(L[i]+d);
    d=L[i]+d;
}
//for(auto x:B)cout<<x <<"\n";
int c=0;
for(auto e:B){
    if(e<=x){c++;}
    else{continue;}
}
cout<<c <<"\n";
}