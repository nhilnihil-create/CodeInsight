#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n",(x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	
    string n;
    cin >> n;
    rep(i,n.length()){
        if(n[i]=='7'){
            Yes();
            return 0;
        }
    }
    No();
    return 0;

}