#include<bits/stdc++.h>
using namespace std;

#define MAXN 5000005
#define ll long long int

int main(){
    int a,b,c,k;
    cin>>a>>b>>c>>k;
    int cnt=0;
    while(b<=a){
        b*=2;
        cnt++;
    }
    while(c<=b){
        c*=2;
        cnt++;
    }
    if(cnt<=k)cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
