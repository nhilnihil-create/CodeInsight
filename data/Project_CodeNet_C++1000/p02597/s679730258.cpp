#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#include <cmath>
#include <cstring>
#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;

char c[200000];

int main()
{
    int i;
    int N;
    cin >> N;

    rep0(i, N)
    {
        cin >> c[i];
    }

    int w=0, r=0;
    int count = 0;

    while (true)
    {
        rep(w,w, N)
        {
            if (c[w] == 'W')
                break;
        }
        rep(r,r, N)
        {
            if (c[N-r-1] == 'R')
                break;
        }
        if(w==N-r)
            break;
        else
        {
            c[w]='R';
            c[N-r-1]='W';
            count++;
        }
    }

    cout << count << endl;
    return 0;
}