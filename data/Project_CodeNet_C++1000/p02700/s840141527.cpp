#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
using ll = long long;
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if((c+b-1)/b>(a+d-1)/d) cout<<"No";
    else cout<<"Yes";
}
