#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll n;cin>>n;
    int mod;
    string s="";
    while(n!=0){
        n--;
        mod=n%26;
        char c=(97+mod);
        s=c+s;
        n/=26;
    }
    cout <<s<<endl;
}
