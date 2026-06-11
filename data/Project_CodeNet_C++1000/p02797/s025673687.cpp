#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,k ; cin>>n>>k;
    ll s; cin>>s;
    if(k>1){
        for(int i=0; i<k-1; i++) cout << s << ' ';
        if(k>0) cout << s;
    }
    else if(k==1) cout << s << endl;
    if(s<pow(10,9)){
        for(int j=0; j<n-k; j++) cout << ' ' << s+1;
    }
    else{
        for(int j=0; j<n-k; j++) cout << ' ' << 1;
    }
    cout << endl;
}