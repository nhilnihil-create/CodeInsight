#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define lli long long int
#define test                lli t;cin>>t;while(t-->0)
#define ainput  int n;cin>>n;int a[n];for(int i=0;i<n;i++){cin>>a[i];}
#define vec vector<lli>v;
vec
#define avinput  int n;cin>>n;int a[n];for(int i=0;i<n;i++){cin>>a[i];v.push_back(a[i]);}
#define vp  for(lli i=0;i<v.size();i++) {cout<<v[i]<<" ";}cout<<endl;
#define vp1  for(lli i=0;i<v1.size();i++) {cout<<v1[i]<<" ";}cout<<endl;
#define vp2  for(lli i=0;i<v2.size();i++) {cout<<v2[i]<<" ";}cout<<endl;
#define vp3  for(lli i=0;i<v3.size();i++) {cout<<v3[i]<<" ";}cout<<endl;
#define vp6  for(lli i=0;i<v6.size();i++) {cout<<v6[i].first<<" "<<v6[i].second<<endl;}
#define vp16  for(lli i=0;i<v16.size();i++) {cout<<v16[i].first<<" "<<v16[i].second<<endl;}
#define ln cout<<endl;
  //cout << fixed << setprecision(10) <<((double)((sum*1.0)/((n*1.0-k*1.0)+1.0))) << endl;
set<lli>s1;
set<lli>s2;
set<string>st2;
vector<lli>v1;
vector<lli>v2;
vector<lli>v3;
vector<lli>v4;
vector<lli>v5;
vector<pair<lli,lli> >v6;
vector<pair<lli,lli> >v16;
vector<string>v7;
vector<string>v8;
vector<char>v9;
vector<double>v11;
list<lli>l;
//****coding start****
int main(){
lli n;cin>>n;
lli a[n],b[n+1];
for(lli i=0;i<n+1;i++){
    cin>>b[i];
}
for(lli i=0;i<n;i++){
    cin>>a[i];
}
lli sum=0;
for(lli i=0;i<n;i++){
    sum=sum+min(a[i],b[i]);
    a[i]=a[i]-min(a[i],b[i]);
    sum=sum+min(a[i],b[i+1]);
    b[i+1]=b[i+1]-(min(a[i],b[i+1]));
}
cout<<sum<<endl;
return 0;
}