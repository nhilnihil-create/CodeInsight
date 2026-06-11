#include<bits/stdc++.h>

using namespace std;

int main(){
int a, b;
cin >> a >> b;
int ans = 0, current_sockets = 1;
while(current_sockets < b){
    current_sockets--;
    ans++;
    current_sockets += a;
}
cout << ans ;
}
