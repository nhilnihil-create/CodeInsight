#include <bits/stdc++.h>
using namespace std;int main(){size_t n,a,b;cin>>n>>a>>b;size_t ave=(a+b)/2;if(ave * 2 == a + b)cout <<  ave - a << endl;else cout<<min(a-1,n-b)+1+(b-a-1)/2<<endl;}