#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<map>
#include<iomanip>


using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define printfloat(x) cout << setprecision(7) << (x) << endl;

long double pi = 3.14159265359;
int n,cnt=0;
string s;

int main(){
    cin >> n;
    cin >> s;
    rep(i,s.size()-1){
        if(s[i] != s[i+1]){
            cnt++;
        }
    }
    cout << cnt+1 << endl;


return 0;
}