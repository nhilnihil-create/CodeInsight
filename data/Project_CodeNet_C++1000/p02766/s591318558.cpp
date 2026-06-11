#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //good luck kittu!
    int n, k; cin>>n>>k;
    int count = 0;
    while(n){
        count++;
        n /= k;
    }
    cout<<count<<"\n";
    return 0;
}