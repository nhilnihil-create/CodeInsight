#include <iostream>
#include <algorithm>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}
int main(void){
    int n;
    cin >> n;
    int p[n];
    for(int i=0;i<n;i++)cin>>p[i];
    int top = 1000000;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(p[i] <= top){
            top = p[i];
            ans++;
        }
    }
    cout << ans;
}
