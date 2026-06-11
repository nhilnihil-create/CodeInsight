#include <bits/stdc++.h>
using namespace std;
#define     LL              long long int
#define     FOR(I,A,B)      for( int I = A; I < B; ++I )
#define     SFI(X)          scanf("%d",&X)
#define     SFL(X)          scanf("%lld",&X)


int main() {

    int n;
    string s;

    scanf("%d",&n);
    cin >> s;

    for(int i=0;i<s.length();i++){
        s[i] = (s[i] - 'A' + n) % 26 + 'A';
    }

    cout << s << endl;

    return 0;
}
