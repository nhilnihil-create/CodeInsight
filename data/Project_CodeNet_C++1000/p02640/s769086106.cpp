#include <bits/stdc++.h>
/*#include <ctime>
#include <list>
#include <numeric>
#include <bitset>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <utility>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stack>
#include <assert.h>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <iomanip>
#include <limits>*/

using namespace std;


/// Bismilahir Rahmanir Rahim


typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef short int si;
typedef unsigned short int usi;
typedef pair <int, int> pii;


#define CASE false
#define TEST false
#define BUFFER true
#define TIME false
#define DEBUG true
#define SET_GEN false
#define File false
#define _ << " " <<
#define __ << "\n"
#define ff first
#define ss second
#define EMPTY_VAL -1
#define RANGE(a, b) (rand() % (b-a+1) + a)


const double pi = acos(-1.);
const double eps = 1e-8;
const int inf = 2147483647;
const int _inf = -2147483648;
const lli INF = 1e18;
const int mod = 1e9+7;
const int maxn = 201;

void delay(int sec); // DEBUG


void solution(void)
{
    int x, y;
    int a, b;

    cin >> x >> y;

    b = y-2*x;
    if (b < 0 || b % 2) cout << "No\n";
    else if (x-(b/2) >= 0) cout << "Yes\n";
    else cout << "No\n";



    return ;
}

int main(int argc, char *arv[])
{
    #if File
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    #if BUFFER
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #endif

    #if SET_GEN
    srand((unsigned int) time(0));
    #endif

    int t = 1;

    #if CASE
    int cnt = 1;
    #endif

    #if TEST
    cin >> t;
    #endif

    #if TIME
    clock_t start_time, end_time;
    double time_elapsed;
    #endif


    while(t--) {

        #if TIME
        start_time = clock();
        #endif

        #if CASE
        cout << "Case #" << cnt++ << ": ";
        #endif

        solution();

        #if TIME
        end_time = clock();

        time_elapsed = (double) (end_time - start_time) / CLOCKS_PER_SEC;

        cout << "\nRuntime: " << fixed << setprecision(7) << time_elapsed << "\n";
        #endif
    }


    return 0;
}

void delay(int sec)
{
    int mili_sec = 1000 * sec;

    clock_t start_time = clock();

    while (clock() < start_time + mili_sec);

    return ;
}
/*
1
6 5
1 2 3
1 5 2
5 4 1
2 3 4
3 6 5
5
6 5
*/
