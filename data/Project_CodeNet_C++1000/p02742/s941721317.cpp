#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC return 0;

using namespace std;
using ll = long long;

/*
int main() {
    ll H, W;
    cin >> H >> W;
    if(H>W) swap(H, W);
    if(H==1)
        cout << 1 << endl;

    else
        cout << (H*W +1)/2 << endl;

        return 0;
}
*/

int main(){

 long long H,W;
 cin>>H>>W;

 if(H>W) swap(H,W);

 if(H == 1)
    cout<<"1"<<endl;
 else
    cout<<(H*W+1)/2<<endl;


return 0;
}