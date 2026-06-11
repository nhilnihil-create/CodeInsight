//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d, e, h1, m1, re;
    cin >>a >> b >> c >> d >>e ;
    h1 = (c - a)*60;
    m1 = d - b;
    re = h1 + m1;
    cout << re - e << endl;



    return 0;
}
