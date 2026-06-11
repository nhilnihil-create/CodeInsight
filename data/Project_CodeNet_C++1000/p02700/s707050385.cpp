#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    int ans = 0;
    cin >> a>>b>>c>>d;
    while(a> 0 && c > 0){
        ans ++;
        if(ans%2 == 1){
            c -= b;
        }else{
            a -= d;
        }
    }
    
    printf("%s",(ans%2 == 1)?"Yes":"No");

}