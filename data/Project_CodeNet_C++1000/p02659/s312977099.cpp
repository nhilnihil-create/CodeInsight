#include <bits/stdc++.h>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;

ll a;
string k;

int main(){
    AC
    cin>>a;
    cin>>k;
    int tt = 1;
    ll tmp = 0;
    for(int i=k.size()-1; i>=0; i--){
        if(k[i]=='.') continue;
        tmp+=(k[i]-'0')*tt;
        tt*=10;
    }
    cout<<(a*tmp)/100<<endl;
}