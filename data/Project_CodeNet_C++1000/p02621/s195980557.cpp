#include <bits/stdc++.h>
using namespace std;

int gcd_func(int a, int b){
    return b? gcd_func(b, a%b) : a;
} 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long a;
    cin >> a;
    cout << a + a*a + a*a*a << endl;
    return 0;
}