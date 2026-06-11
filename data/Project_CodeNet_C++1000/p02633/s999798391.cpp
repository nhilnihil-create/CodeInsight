#include <bits/stdc++.h>
#define pb push_back
#define f first
#define sc second
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x; cin >> x;
    for(int i = 1;;i++) if(i*x % 360 == 0){
        cout << i << "\n";
        break;
    }
}
