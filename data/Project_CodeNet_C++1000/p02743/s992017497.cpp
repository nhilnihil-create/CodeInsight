#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int MAX_N = 1000;         // n の最大値

// nCk を取得
void f(int res , string s){
     if(res==0){
       cout << s << endl;}
   else{
     for(char c='a'; c<='c'; c++){
        f(res -1, s + c);}
   }
}
double nCk(int n, int k) {
double res=1.0;
for(int i=0; i<n; i++){
res*=0.5;}
for(int i=0; i<k; i++){
res*=(double)(n-i);
res/=(double)(k-i);
}
return res;}

int main() {
cout << fixed << setprecision(8);
long double a,b,c;
cin>>a>>b>>c;
long double d = a*b;
if(c-a-b<=0){
cout<<"No"<<endl;}
else{
long double e = (c-a-b)*(c-a-b)/4;
if(d<e){
cout<<"Yes"<<endl;}
else
cout<< "No" <<endl;}}
