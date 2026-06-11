#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
int main(){
string s,t;
cin>>s>>t;
ll ca = 0;
for(ll i=0; i<3; i++){
if(s.at(i)==t.at(i)){
ca++;}}
cout << ca << endl;}