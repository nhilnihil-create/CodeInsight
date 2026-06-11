#include<iostream>
using namespace std;

int main(){
    int a,b,c,ans;
    cin >> a >> b >> c;
    if((a - b) >= c){
        ans = 0;
    }
    else{
        ans = c - (a - b);
    }

    cout << ans << endl;
    
    return 0;
}