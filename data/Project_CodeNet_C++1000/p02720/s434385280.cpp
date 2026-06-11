#include <bits/stdc++.h>
#define int long long

#define mp make_pair
#define pb push_back
#define mod (int)1e9+7
using namespace std;

set<int> s;
void func(int x,int lst,int n){
    s.insert(x);
    if(n >= 11) return;
    if(lst == 9){
        func(x*10+9,9,n+1);
        func(x*10+8,8,n+1);
        return;
    }
    if(lst == 0){
        func(x*10+0,0,n+1);
        func(x*10+1,1,n+1);
        return;
    }
    func(x*10+lst,lst,n+1);
    func(x*10+lst-1,lst-1,n+1);
    func(x*10+lst+1,1+lst,n+1);
    return;
}

signed main(){
    int n;
    cin >> n;
    for(int i =1;i<10;i++) func(i,i,1);
    n--;
    while(n--){
        s.erase(s.begin());
    }
    cout << *s.begin();
}
