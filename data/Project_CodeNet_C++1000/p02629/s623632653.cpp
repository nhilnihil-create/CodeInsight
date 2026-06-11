#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n;
    string s="";
    cin >> n;
    while(n>0){
        n-=1;
        s+=char('a'+(n)%26);
        n/=26;
    }
    reverse(s.begin(),s.end());
    cout << s;
}