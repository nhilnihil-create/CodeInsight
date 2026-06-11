#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
int n;
cin>>n;
vector <int> W(n),B,A,S,D;
for(auto &e:W)cin>>e;
int t=1;
while(t<n){
    for(int i=0;i<n;i++){
        if(i<t){B.emplace_back(W[i]);}
        else{A.emplace_back(W[i]);}
    }
    int s=accumulate(B.begin(),B.end(),0);
    int s1=accumulate(A.begin(),A.end(),0);
    S.emplace_back(abs(s-s1));
    B.clear();
    A.clear();
    t++;
}
cout<<*min_element(S.begin(),S.end()) <<"\n";
}