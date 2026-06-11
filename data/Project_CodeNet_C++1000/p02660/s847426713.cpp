#include <bits/stdc++.h>
#define ll long long
#define ar array
#define nl '\n'
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 1e6;

int arr[N+5];
ll n;
int ans=0;
int num_prime = 0;


int main(){
    AC
    cin>>n;
    ll twos = 2;
    while(n%twos==0){
        n/=twos;
        twos*=2;
        ans++;
    }
    while(n%2==0)
        n/=2;

    for(int i=3; i<=sqrt(n); i+=2){
        if(n%i==0){
            // i is prime
            ll p = i;
            while(n%p==0){
                n/=p;
                p*=i;
                ans++;
            } 
            while(n%i==0)
                n/=i;
        }
    }
    if(n>2)
        ans++;
    cout<<ans<<endl;
}