#include <iostream>
using namespace std;
int main(void){
    int n,x,i,l,now=0,cnt=1;
    cin >> n >> x;
    for(i=0;i<n;i++){
        cin >> l;
        now+=l;
        if(now<=x) cnt++;
        else break;
    }
    cout << cnt;
}