#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n,x,t;
    cin>>n>>x>>t;
    cout<<std::fixed;
    cout<<(int)(ceil(n/(x*1.0))*t);
}