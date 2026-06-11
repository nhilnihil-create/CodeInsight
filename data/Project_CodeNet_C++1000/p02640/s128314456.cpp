#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int x,y;
    cin >> x >> y;
    if( ((y-2*x)%2==0 && y-2*x>=0) && ((4*x-y)%2==0 && 4*x-y>=0) )
        cout << "Yes" << endl;
    else cout << "No" << endl; 
    return 0;
}