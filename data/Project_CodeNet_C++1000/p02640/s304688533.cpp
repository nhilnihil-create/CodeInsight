#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep2(i,x,n) for (int i = x; i < n; i++)
using ll = long long int;
int main() {
    int x,y;
    cin >> x >> y;
    if((y-2*x)/2>=0 && (y-2*x)%2==0 && (4*x-y)/2>=0 &&(4*x-y)%2==0) cout << "Yes" << endl;
    else cout << "No"  << endl;
    return 0;
}