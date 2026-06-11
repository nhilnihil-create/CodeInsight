#include <iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>
#include<cmath>
#include<iomanip>
#include<queue>
#include<string>
using namespace std;

const double PI  =3.141592653589793238463;
#define pb push_back
#define pf push_front
#define sz(v)  ((int)(v).size());
#define all(v) ((v).begin()),((v).end())
typedef unsigned long long ull;
typedef long long ll;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ull> vul;

typedef pair<int,int> pi;
//2 7 3 4 9

void printVec(vul v1)
{
    for(int i=0; i<v1.size(); i++)
        cout<<v1[i]<<" ";
    cout<<endl;
}
ll rec(ll r,ll c){

if(r<=1 || c<=1){
    return 1;
}


return rec(r-1,c)+rec(r,c-1);
}

bool bin_search(ull  target, vul V){

ll low=0;
ll high=V.size()-1;
while(low<=high){
    ll mid=(low+high)/2;
    if(target==V[mid]){
        return true;
    }
    if(target <V[mid]){
        high=mid-1;
    }else{
    low=mid+1;
    }
}
return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
ll n,m,k;cin>>n>>m>>k;
vul a(n,0);
vul b(m,0);

for(ll i=0;i<n;i++){
cin>>a[i];
}
for(ll i=0;i<m;i++){
cin>>b[i];
}

vul A(n+1,0);
vul B(m+1,0);

for(ll i=0;i<n;i++){
A[i+1]=A[i]+a[i];
}
for(ll i=0;i<m;i++){
B[i+1]=B[i]+b[i];
}

ll books=0,A_books=0,B_books=0;
ull sum=0;

 vector<ull>::iterator lower,upper;
for(ull i=0;i<=n;i++){

ll t=k-A[i];
if(t < 0){
    continue;
}
 lower = lower_bound(B.begin(),B.end(),k-A[i]);
B_books=lower-B.begin();
if(B[B_books] >k-A[i] ||B_books>m){
    B_books--;
}
//B_books--;
sum=max(sum,B_books+i);

}
cout<<sum<<endl;
  return 0;
}
