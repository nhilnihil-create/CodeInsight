#include <bits/stdc++.h>

using namespace std;

#define int long long
#define tie() ios_base :: sync_with_stdio(0); cin.tie(0) ; cout.tie(0)
#define err(x) cerr << #x << " is : " << x << endl
#define mem(a , v)   memset(a , v , sizeof a)
#define all(v) v.begin() , v.end()
#define endl '\n'


int32_t main()
{
      tie();
      int t = 1;
      while(t--)
      {
            int k;
            cin >> k;
            queue <int> q;
            for(int i = 1 ; i <= 9 ; i++)
                q.push(i);

            int ctr = 0;
            while(true)
            {
                int fr = q.front();
                q.pop();
                ctr++;
                if(ctr == k)
                {
                    cout << fr << endl;
                    return 0;
                }
                int x = fr % 10;

                if(x != 0)
                    q.push(fr * 10 + x - 1);

                q.push(fr * 10 + x);

                if(x != 9)
                    q.push(fr * 10 + x + 1);
            }
      }
      return 0;
}
