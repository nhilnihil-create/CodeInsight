# include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;

int main(){
int k,n;
cin>>k>>n;
k=k-1;
for(int i=n-k;i<=n+k;i++)
    cout<<i<<" ";
}
