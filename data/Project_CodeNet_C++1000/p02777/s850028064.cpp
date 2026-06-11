#include <bits/stdc++.h>
using namespace std;

int main() {
string S,T,U;
cin >> S>>T;
int a,b;cin>>a>>b>>U;
if(S.compare(U)==0) {cout<<a-1<<" "<<b<<endl;}else {cout<<a<<" "<<b-1<<endl;}
return 0;
}
