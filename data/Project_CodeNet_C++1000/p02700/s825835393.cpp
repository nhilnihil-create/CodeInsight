#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int a,b,c,d;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    int turn = 1;
    while (a>0 && c>0){
        if(turn){
            c -= b;
        } else {
            a -= d;
        }
        turn = 1-turn;
    }
    if(!turn) cout << "Yes\n";
    else cout << "No\n";
    
    return 0;
}