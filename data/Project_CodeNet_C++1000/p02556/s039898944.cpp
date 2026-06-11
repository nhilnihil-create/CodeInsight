#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mxn= 5e5+5;
// check for forloop
// intialize variable
// overflow
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    rishabh();
    int n;
    cin>>n;
    vector<ll> pos, neg;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        pos.push_back(x+y);
        neg.push_back(x-y);
    }
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    cout<<max(pos[n-1]-pos[0], neg[n-1]-neg[0]);
}