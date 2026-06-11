#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define ll         long long
#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

int main(){
    string W, T;
    cin >> W;
    transform(W.begin(), W.end(), W.begin(), ::toupper);
    int ans = 0;
    while(1){
        cin >> T;
        if(T=="END_OF_TEXT") break;
        if(T[T.length()-1]=='.') T.erase(T.end());
        if(T[0]=='"'){
            T.erase(T.begin());
            T.erase(T.end());
        }
        transform(T.begin(), T.end(), T.begin(), ::toupper);
        if(T==W) ans++;
    }
    cout << ans << endl;
}