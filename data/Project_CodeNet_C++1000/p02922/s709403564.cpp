#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
ll a,b;
cin >> a >> b;
if((b-1)%(a-1)) cout << (b-1)/(a-1)+1;
else cout <<(b-1)/(a-1);
return 0;
}