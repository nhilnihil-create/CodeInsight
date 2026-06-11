#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define   ll long long int
#define inf 1000000




int main(){

int h,w,m;
cin>>h>>w>>m;
map<int,int> r;
map<int,int> c;
map<int,map<int,int> > mat;
vector<pair<int,int> > tp;
for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    r[a]++;
    c[b]++;
    mat[a][b]++;
    tp.push_back({a,b});
}
int max1=0;
ll ans;
vector<int> px;
for(auto x: r){
    max1=max(max1,x.second);
}

for(auto x: r){
    if(x.second==max1){
        px.push_back(x.first);
    }
}
ans=max1;
sort(px.begin(),px.end());
max1=0;

vector<int> py;
for(auto x: c){
    max1=max(max1,x.second);
}

for(auto x: c){
    if(x.second==max1){
        py.push_back(x.first);
    }
}
ans+=max1;
sort(py.begin(),py.end());

ll totc= (ll)py.size()*px.size();

for(auto x: tp){
    int a=x.first;
    int b=x.second;
    if(binary_search(px.begin(),px.end(),a) && binary_search(py.begin(),py.end(),b) )
        totc--;
}

if(totc>0){
    cout<<ans<<endl;
}
else{
    cout<<ans-1<<endl;
}
}
