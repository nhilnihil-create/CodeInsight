#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

bool is_integer(double x) {
    return std::floor(x)==x;
}

int main(){
    int x;  cin >> x;
    if(x==0){
        puts("1");
    }else{
        puts("0");
    }
    
    return 0;
}