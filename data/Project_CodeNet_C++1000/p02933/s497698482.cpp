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

int main(){
    fastio;
    int a;
    string resp;
    cin >> a;
    cin >> resp;
    if(a>=3200){
        cout << resp << endl;
    }else{
        cout << "red" << endl;
    }
    return 0;
}