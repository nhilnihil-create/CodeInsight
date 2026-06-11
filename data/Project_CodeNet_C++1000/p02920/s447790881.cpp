#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
  if ( a > b )
    return 1;
  if ( a == b )
    return 0;
  return 0;
}

int doiLaN;
vector <int> s(1 << 18), goodSlimes, viz(1 << 18, 0);

int checkFather()
{
    int length = goodSlimes.size(), weAreGoodHere = 0;
    int poz = 0, nr = 0, n = doiLaN;
    //cout << length << " " << n << "\n";

    for (int i = n - 1; i >= 0; i--)
    {
        //cout << viz[i] << " " << i << "\n";
        if (viz[i] == 0)
        {
            if (goodSlimes[poz] > s[i])
            {
                viz[i] = 1; poz++;
                goodSlimes.push_back(s[i]);
            }

            if (poz == length)
                return 1;
            // {
            //     sort(goodSlimes.begin(), goodSlimes.end(), descrescator);
            //     return 1;
            //     i = n + 1;
            // }
        }

        if (i == 0)
          return 0;

    }
    //cout << "\n";
    //if (nr == length)
      //  weAreGoodHere = 1;
    return 1;
}

int main()
{
    int n;

    cin >> n;

    doiLaN = (1 << n);

    for (int i = 0; i < doiLaN; i++)
    {
        cin >> s[i];
    }
    //cout << s[0] << " ";

    sort(s.begin(), s.begin() + doiLaN);

    //cout << s[0];
    int poz = 0;
    goodSlimes.push_back(s[doiLaN - 1]);
    viz[doiLaN - 1] = 1;

    while(poz < n)
    {
        if (checkFather() == 0)
            {
                cout << "No\n";
                return 0;
            }
        poz++;
        sort ( goodSlimes.begin(), goodSlimes.end(), cmp);
    }

    cout << "Yes\n";

    return 0;
}
