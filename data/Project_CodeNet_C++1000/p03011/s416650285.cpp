#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);
int p,q,r;
cin>>p>>q>>r;
int s=p+q,s1=p+r,s2=r+q;
cout<<min(min(s,s1),s2) <<"\n";
}