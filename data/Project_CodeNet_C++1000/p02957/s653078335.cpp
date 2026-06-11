#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define phi 3.1415926535
 
using namespace std;
 
ll tc, cnt = 0, number, many, total = 0;
int rmove[4] = {0, 0, -1, 1};
int cmove[4] = {1, -1, 0, 0};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // g++ -std=c++11 Default.cpp  -o test

    ll arr[2];
    cin >> arr[0] >> arr[1];

    ll sum = arr[0] + arr[1];
    if(sum % 2 == 0)
        cout << sum / 2;
    else
        cout << "IMPOSSIBLE";
    cout << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
    return 0;
}