#include <bits/stdc++.h>
using namespace std;

int main(){
    int s;
    cin >> s;
    long long ans=0;
    for (int i=1; i <= s; i++){
        if(i%3!=0 && i%5!=0)ans+=i;
    }
    cout << ans << endl;
    
}