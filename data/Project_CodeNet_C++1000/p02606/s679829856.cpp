
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 100009
#define mod 1000000007
#define ll long long
#define pb push_back
using namespace std;
#ifdef _WIN32
#define WINPAUSE system("pause")
#endif


int main()
{

         ll  L ,R,d;
         cin >> L >> R >> d;
       
         int cnt{ 0 };
         while (L <= R)
         {
             if (L % d == 0)
                 ++cnt;

             ++L;
         }
         cout << cnt << '\n';
        
    
     //cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
