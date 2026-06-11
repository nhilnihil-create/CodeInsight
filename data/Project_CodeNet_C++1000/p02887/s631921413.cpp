#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;
    string a;
    cin >> a;

    int ans=0;
    for(int i=1;i<=num;i++){
        if(a[i-1]!=a[i]){
            ans++;
        }
    }
    cout << ans << endl;
}