#include <iostream>
#include <algorithm>
#include <string>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin>>n;
    ll total=0;
    ll price[1001];
    ll p;
    cin>>p;
    for (ll i = 0; i <n ; ++i) {
        cin>>price[i];
    }
    sort(price,price+n);
    for (int j = 0; j <p ; ++j) {
        total+=price[j];
    }
    cout<<total<<endl;
}