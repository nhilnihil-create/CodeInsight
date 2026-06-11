#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;


int main(){
int X;
cin>>X;
string ans = "0";
for(int i = 0; i <= X;i++){
if(100*i <= X && X <= 105*i)ans = "1";
}
cout<<ans<<endl;
}
