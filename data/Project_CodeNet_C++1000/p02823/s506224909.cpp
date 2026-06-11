#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,n;
int main(){
    cin >> n >> a >> b;
    if ((b-a)&1){
        cout << min(((a-1)+(b-1)+1)/2,((n-a)+(n-b)+1)/2) << endl;
    } else {
        cout << (b-a)/2 << endl;
    }
    return 0;
}
