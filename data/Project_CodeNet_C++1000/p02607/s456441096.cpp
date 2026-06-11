#include <iostream>
//#include <algorithm>
//#include <string>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin>>n;
    ll cuo=0;
    ll arr[101];
    for (ll i = 1; i <n+1 ; ++i) {
        cin>>arr[i];
    }
    for (ll i = 1; i <n+1 ; ++i) {
        if(arr[i]%2!=0&&i%2!=0){
            cuo++;
        }
    }
    cout<<cuo<<endl;
}