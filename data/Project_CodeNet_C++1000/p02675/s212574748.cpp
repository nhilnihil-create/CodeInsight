#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    IOS; int n; cin >> n;
    if(n%10==3) cout << "bon";
    else if(n%10==0 || n%10==1 || n%10==6 || n%10==8) cout << "pon";
    else cout << "hon";
    return 0;
}
