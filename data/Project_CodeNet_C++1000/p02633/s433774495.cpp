#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100000 + 10;
int main(){
    ios::sync_with_stdio(0);
    int x; cin>>x;
    for(int i=2;;i++){
        if(x*i%360==0) return !printf("%d\n",i);
    }
}
