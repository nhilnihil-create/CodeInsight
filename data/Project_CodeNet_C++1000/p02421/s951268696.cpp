#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
cin>>n;
int T=0,H=0;
for(int i=0;i<n;i++){
string t,h;
cin>>t>>h;

for(int g=0;g<t.size();g++){
if(t[g]>h[g]){T+=3; break;}
if(t[g]<h[g]){H+=3; break;}
if(g+1==t.size() && t[g+1]<h[g+1]){H+=3; break;}
if(g+1==t.size() && t[g]==h[g]){T+=1; H+=1;}
}}

cout<<T<<" "<<H<<endl;

return 0;
}
