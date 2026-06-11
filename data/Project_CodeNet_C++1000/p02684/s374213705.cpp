#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
ll n, k;
cin>>n>>k;
vector<ll> a(n+1);
for(ll i = 1; i < n+1; i++){
    cin>>a[i];
}
ll count=1;
map<ll, ll> m;
ll present = 1;
ll loopsize = 0;
ll temp, start;
while (count < n+1)
{
    if(m[present]){
        loopsize = count - m[present];
        start = m[present] - 1;
        break;
    }
    temp = present;
    m[present] = count;
    present = a[present];
    count++;
}
//cout<<loopsize<<" "<<temp<<" "<<start<<" "<<present<<endl;
if(loopsize == 0){
    cout<<temp;
}else
{
    if(k <= start){
        ll p = 1;
        for(ll i = 0; i < k; i++){
            p = a[p];
        }
        cout<<p;
    }else
    {
        k -= start;
        k %= loopsize;
        ll p = present;
 //       cout<<k<<endl;
        for(ll i = 0; i < k; i++){
            p = a[p];
        }
        cout<<p;
    }
    
}
return 0;    
}