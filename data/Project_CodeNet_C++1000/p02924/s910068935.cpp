#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
ll n;cin >> n;
ll sum = 0;
sum += n*(n-1)/2;
cout << sum;
return 0;
}