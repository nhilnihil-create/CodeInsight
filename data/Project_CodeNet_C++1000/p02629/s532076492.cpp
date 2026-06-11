#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll int n,k,l;
    vector<ll> s;
    cin >> n;
  n--;
    while(n>=0){
        k=n%26;
        n/=26;
      n--;
        s.push_back(k);
    }
    l=s.size();
    for(int i=l-1;i>=0;i--){
        cout << (char)(s[i]+'a');
    }
}