#include <bits/stdc++.h>
using namespace std;int main(){int n;char c[10002];cin>>n>>c;for(int i=0; c[i] != '\0'; i++){c[i] = 'A' + (c[i]-'A'+n) % 26;}cout<<c<<endl;}