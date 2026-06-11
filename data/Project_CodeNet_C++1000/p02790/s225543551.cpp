#include <iostream>
#include <algorithm>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}
int main(void){
    int a,b;
    int ans = 0;
    cin >> a >> b;
    if(a > b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    for(int i=1;i<=b;i++){
        ans = ans * 10 + a;
    }
    cout << ans ;
}
