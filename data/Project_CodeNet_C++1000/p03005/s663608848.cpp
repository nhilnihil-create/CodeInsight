#include<bits/stdc++.h>
using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    FastIO();
    int n,k;
    cin>>n>>k;
    cout<<(k == 1 ? 0 : n%k);
    return 0;
}