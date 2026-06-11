#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int c=n%10;
    n=n/10;
    if (c==2||c==4||c==5||c==7||c==9)cout << "hon\n";
    else if (c==0||c==1||c==6||c==8)cout << "pon\n";
    else if (c==3)cout << "bon\n";
        return 0;
}
