#include <iostream>
#include <string>
#include <vector>

using namespace std;

string to_str(int n)
{
    string num;
    while(n > 0)
    {
        num = (char)(n % 10 + '0') + num;
        n /= 10;
    }
    return num;
}

bool is_all_seven(const string& n)
{
    for(auto c : n)
    {
        if(c != '7')
            return false;
    }
    return true;
}

int main()
{
    long long K; cin >> K;

    long long s = 0, ans = 0;
    while(true)
    {
        for(int i=0; i<10; ++i)
        {
            if(s % 10 == 7)
                break;

            if(i == 9)
            {
                cout << -1 << endl;
                return 0;
            }

            s += K;
        }
        ++ans;
        s /= 10;

        string num = to_str(s);
        if(is_all_seven(num))
        {
            ans += num.size();
            break;
        }
    }

    cout << ans << endl;
}