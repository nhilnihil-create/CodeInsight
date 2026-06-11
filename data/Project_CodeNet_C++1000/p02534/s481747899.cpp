//REPEAT ACL ATCODER BEGINNER CONTEST
#include <bits/stdc++.h>
using namespace std;
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
int main()
{
  	IOS
    int k;
    cin >> k;
    string s = "ACL";
    int i;
    for (i = 1; i < k; i++)
    {
        s += "ACL";
    }
    cout << s;
    return 0;
}