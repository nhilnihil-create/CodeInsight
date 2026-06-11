#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>a,b,c,d;
int n,m,q;
int ans = 0;
void brute(int sz,int last,vector<int>v){
if(sz==n){
        int sum = 0;
    for(int i = 0;i<q;i++){
        if(c[i]==v[b[i]-1]-v[a[i]-1]){
            sum += d[i];
        }
    }
    ans = max(ans,sum);
}
else{
    for(int i = last;i<=m;i++){
        v[sz] = i;
        brute(sz+1,i,v);
    }
}
}
int main(){
cin >> n >> m >> q;
a.resize(q);
b.resize(q);
c.resize(q);
d.resize(q);
for(int i = 0;i<q;i++){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
}
vector<int>v(n);
for(int i = 1;i<=m;i++){
    v[0] = i;
    brute(1,i,v);
}
cout << ans;
}
