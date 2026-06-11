#include<bits/stdc++.h>
using namespace std;

int main(){
    long long h,ans=1;
    cin >> h;
    int i=0;
    while(true){
        if(h/2!=0){
            i++;
            h=h/2;
        }
        else break;
    }
    i++;
    for(int j=0;j<i;j++){
        ans*=2;
    }
    cout << ans-1 << endl;
    return 0;
}