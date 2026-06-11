#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string S;
    cin >> S;
    vector<long long> a(S.size() + 1);
    vector<long long> b(S.size() + 1);
    vector<long long> c(S.size() + 1);

    for (int i = 0; i <= S.size() - 1; i++)
    {
        if (S[i] == '<') a[i + 1] = a[i] + 1;
    }

    for (int i = S.size() - 1; i >= 0; i--)
    {
        if (S[i] == '>') b[i] = b[i + 1] + 1;
    }
    
    long long ans = 0;
    for (int i = 0; i < c.size(); i++)
    {
        c[i] = max(a[i], b[i]);
        ans += c[i];
    }
    
    cout << ans << endl;
    
    return 0;
}