#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
ll n;cin >> n;
ll sum = 0;
for(ll i = 1;i<n;i++) sum += i;
cout << sum;
return 0;
}