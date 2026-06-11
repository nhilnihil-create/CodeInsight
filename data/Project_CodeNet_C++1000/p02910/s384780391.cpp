#include <bits/stdc++.h>
using namespace std;

#define MOD 10000007
#define f first
#define s second
#define es " "
#define pb push_back
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define ll long long int
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define sz(x) (int)x.size()
typedef pair<int, int> pii;

int main(){
    fastio;
    int a, b, c, x;
    string at1, at2;
    cin >> at1;
    for(int i=0; i<sz(at1); i++){
        if(i%2==0 && (at1[i]=='R' || at1[i]=='U' || at1[i]=='D')){
            continue;
        }else if(i%2!=0 && (at1[i]=='L' || at1[i]=='U' || at1[i]=='D')){
            continue;
        }else{
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}