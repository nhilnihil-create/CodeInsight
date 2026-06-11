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

    cin >> many;

    ll monster[many + 1];
    for(int i = 0; i < many + 1; i++)
        cin >> monster[i];

    ll hero[many];
    for(int i = 0; i < many; i++)
        cin >> hero[i];

    ll answer = 0;
    for(int i = 0; i < many; i++)
    {
        if(monster[i] > 0)
        {
            ll temp = min(monster[i], hero[i]);
            monster[i] -= temp;
            hero[i] -= temp;
            answer += temp;
        }

        if(monster[i + 1] > 0)
        {
            ll temp = min(monster[i + 1], hero[i]);
            monster[i + 1] -= temp;
            hero[i] -= temp;
            answer += temp;
        }
    }

    cout << answer << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
    return 0;
}