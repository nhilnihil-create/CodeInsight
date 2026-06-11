#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int a[n]; memset(a, 0, sizeof(a));
    int pena[n]; memset(pena, 0, sizeof(pena));
    int ansNum = 0, penalty = 0;
    for(int i = 0; i < m; ++i){
        int p; string s;
        cin >> p >> s;
        p--;
        if(a[p] == 0 && s == "WA") pena[p]++;
        if(a[p] == 0 && s == "AC") {
            ansNum++;
            a[p] = 1;
        }
    }
    for(int i = 0; i < n; ++i){
        if(a[i]) penalty += pena[i];
    }
    cout << ansNum << " " << penalty << endl;
    return 0;
}