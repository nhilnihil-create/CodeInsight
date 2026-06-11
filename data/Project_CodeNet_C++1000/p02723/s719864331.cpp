#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n",(x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)

int main(){
	
    string s; cin >> s;
    if(s[2]==s[3]&&s[4]==s[5])Yes();
    else No();
    return 0;

}