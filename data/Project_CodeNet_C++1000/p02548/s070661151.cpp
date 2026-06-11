#include <bits/stdc++.h>
#define ll  long long int
#define out  cout<<

using namespace std;



int main(){
    ll n;
    cin>>n;
    ll no_of_b=0;
    for(ll i=1;i<n;i++){
        no_of_b += (n-1)/i;
    }
    cout<<no_of_b<<endl;
return 0;}
