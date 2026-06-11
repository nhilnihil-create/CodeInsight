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
	
    int n;
    cin >> n;
    long long ans=0;
    rep(i,n){
        if(i%3!=0&&i%5!=0) ans +=i;
    }
    cout << ans << endl;
    return 0;

}