#include<bits/stdc++.h>

using namespace std;
#define ll long long int

int main(){
ll n, k;
cin >> n >> k;
cout << min(abs(k-(n%k)), n%k);

}
