#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int main() {
//cout << fixed << setprecision(10);
string s;
cin>>s;
ll ca=0;
ll n=s.size();
int f=0;
for(int i=0; i<n; i++){
if(f==0){
ca++;
f=1;
continue;}
else if(s.at(i)==s.at(i-1)){
ca++;
i++;
if(i==n) ca--;
f=0;}
else{
f=1;
ca++;}}
cout<<ca<<endl;}
