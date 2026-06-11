#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,C,k;
    cin>>A>>B>>C>>k;
    int ans=0;
    while(A>=B){ B*=2;ans++;}
    while(B>=C){ C*=2;ans++;}
    if(ans<=k) cout<<"Yes\n";
    else cout<<"No\n";
}