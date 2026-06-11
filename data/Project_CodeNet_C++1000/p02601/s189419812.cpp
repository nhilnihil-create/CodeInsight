#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5;
const int maxm = 5e5 + 5;
const ll inf = 2147483647;

int main(){
    int a, b, c, k;
    cin>>a>>b>>c;
    cin>>k;
    while (b <= a){
        b *= 2;
        k--;
    }
    while (c <= b){
        c *= 2;
        k--;
    }
    if(k >= 0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
