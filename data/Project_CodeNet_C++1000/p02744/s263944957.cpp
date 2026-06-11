#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;
void sol(int pos, int used, string s){
    if(pos == n){
        cout << s << endl;
        return;
    }
    char c = 'a';
    for(int i=0; i<used; i++){
        sol(pos+1, used, s+c);
        c++;
    }
    sol(pos+1, used+1, s+c);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    sol(1, 1, "a");
    return 0;
}
