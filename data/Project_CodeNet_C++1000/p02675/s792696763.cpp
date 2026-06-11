#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    int N; cin >> N;
    int x;
    if(N>=10) x=N%10;
    else x=N;
    if(x==3) cout << "bon" << endl;
    else if(x==0 || x==1 || x==6 || x==8) cout << "pon" << endl;
    else cout << "hon" << endl;
    return 0;
}