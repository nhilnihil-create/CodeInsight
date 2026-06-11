#include <bits/stdc++.h>
using namespace std;
#define loop(i,n) for (int i =0;i<(n);i++)
typedef long long ll;



int main(){

    int n,r;
    cin >> n>>r;
    int ans  = r+100*max(0,10-n);
    cout<<ans<< endl;
    return 0;
}