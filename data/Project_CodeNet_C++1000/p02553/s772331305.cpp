#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define print(x) cout << #x << '=' << x << endl

int main()
{
    long long a,b,c,d;
	long long ans1,ans2,ans3,ans4;
    cin >> a >> b >> c >> d;

    ans1 = a*c;
    ans2 = a*d;
    ans3 = b*c;
    ans4 = b*d;

    cout << max(ans1 , max(ans2 , max(ans3,ans4))) << endl;
    return 0;
}