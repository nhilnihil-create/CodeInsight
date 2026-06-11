#include <iostream>
using namespace std;
#define int long long

signed main(){
// Your code here!
int i,p;
int ans = 0;
cin >> i;
p=100;

for(int o=1;;o++){
    p += (p/100);
    if(p>=i){
        cout << o;
        return 0;
    }
}
/*
while(p < i)
{
    ans ++;
    p *= 1.01;
}
cout << ans;
*/


}
