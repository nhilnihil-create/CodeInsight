#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int h,w,n;
int main(void){
    cin>>h>>w>>n;
    cout<<(n+max(h,w)-1)/max(h,w)<<endl;
    
}
