#include <bits/stdc++.h>
using namespace std;
int main(){long long n,a=0; cin>>n; if(n%2) return puts("0"),0; for(n/=10;n;n/=5)a+=n; cout<<a;}