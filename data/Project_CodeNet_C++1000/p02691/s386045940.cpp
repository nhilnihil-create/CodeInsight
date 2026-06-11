#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;


main(){
    int n;cin>>n;
    int a[n];
    map<ll,int> ht;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ht[i+a[i]]++;
    }
    ll count=0;
    for(int i=0;i<n;i++){
        if(ht.find(i-a[i])!= ht.end()){
            count+= ht[i-a[i]];
        } 
    }
    cout<<count;
}