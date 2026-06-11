
// Problem: A - Calc
// Contest: AtCoder - AtCoder Beginner Contest 172
// URL: https://atcoder.jp/contests/abc172/tasks/abc172_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)



    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    #define FAST ios_base::sync_with_stdio(false);cin.tie(0);
    const double EPS = 1e-9;
    const double PI = acos(-1);
    const int knightDir[8][2] = {{-2,-1},{-2,1},{-1,2},{1,2},{2,-1},{2,1},{-1,-2},{1,-2}};
    //const int dx[]={0,0,0,1,1,1,-1,-1,-1};
    //const int dy[]={-1,0,1,-1,0,1,-1,0,1};
    const int dx[] = {0 , 1 , 0 , -1};
    const int dy[] = {1 , 0 , -1 , 0};
    //#define MOD         1000000007LL
    #define MAX         1000005
    const ll MOD = 1000000000 + 7;
    
    int main()
    {
        FAST
        int t;
        t = 1;

        while(t--)
        {
           int n;
           cin >> n;
           
           cout << n + (n * n) + (n * n * n) << endl;
        }
    }

