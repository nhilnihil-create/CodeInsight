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
    if(at1=="Sunny"){
        cout << "Cloudy" << endl;
    }
    if(at1=="Cloudy"){
        cout << "Rainy" << endl;
    }
    if(at1=="Rainy"){
        cout << "Sunny" << endl;
    }
    return 0;
}