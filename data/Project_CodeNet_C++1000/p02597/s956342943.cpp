#include <bits/stdc++.h>
using namespace std;
#define INF 1e9+7
typedef long long int ll;
const int maxn = 1000000;
ll mod = INF;

int n;
string s;

int main(){
    cin >> n;
    cin >> s;
    int R=0,W=0;
    int todoR=0,todoW=0;
    for(int i=0;i<n;i++){
        if(s[i]=='R')R++;
    }
    W=n-R;

    for(int i=0;i<R;i++){
        if(s[i]=='W')todoW++;
    }

    for(int i=R;i<n;i++){
        if(s[i]=='R')todoR++;
    }

    //ans =  min(todoR,todoW)+max(todoR,todoW)-min(todoR,todoW)
    cout << max(todoR,todoW)<<endl;

    return 0;
}