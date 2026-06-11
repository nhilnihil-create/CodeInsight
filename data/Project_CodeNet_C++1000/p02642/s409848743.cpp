#include<iostream>
#include<cstdio>
using namespace std;
const int N = 200005;
int a[N];
int Cnt[1000005];
bool Check(int x) {
    if(Cnt[1] && x != 1) return false;
    if(x == 1) {
        if(Cnt[1] > 1)return false;
        else return true;
    }
    for(int i = 2; i*i <= x; ++i) {
        if(!(x%i)) {
            if(Cnt[i] || Cnt[x/i]) return false;     
        }
    }
    if(Cnt[x] > 1) return false;
    return true;
}
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        scanf("%d",&a[i]);
        ++Cnt[a[i]];
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        if(Check(a[i])) ++cnt;
    }
    cout << cnt << '\n';
return 0;
}