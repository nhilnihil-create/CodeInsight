#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll a,b;
    cin >> a >> b;
    vector<ll> a_prime;
    a_prime.push_back(1);
    ll c=a;
    for(ll i=2; i*i<=a; i++){
        if(c%i == 0){
            a_prime.push_back(i);
            while(c%i==0){
                c  /= i;
            }
        }
    }
    if(c != 1){
        a_prime.push_back(c);
    }
    int count=0;
    for(int i=0; i<a_prime.size(); i++){
        ll k=a_prime.at(i);
        if(b%k==0) count++;
    }
    cout << count << endl;
}
