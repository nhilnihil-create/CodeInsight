#include <iostream>
#include <vector>

using namespace std;

unsigned long long int power(int times)
{
    unsigned long long int pow = 1;
    for (int i = 0 ; i < times ; i++)
        pow *= 26;
    return pow;
}

int main()
{
    unsigned long long int n, mini = 1, maxi = 26, diff, sub;
    int i;
    cin >> n;
    for (i = 1 ; i <= 15 ; i++)
    {
        if (n >= mini && n <= maxi)
            break;
        mini = maxi + 1;
        maxi = maxi + power(i+1);
    }
    vector<int> digits(i, 0);
    diff = n - mini;
    sub = diff / 26;
    digits[0] = diff - 26 * sub;
    for (int j = 1 ; sub > 0 ; j++)
    {
        if (sub < 26)
        {
            digits[j] = sub;
            break;
        }
        else
        {
            diff = sub;
            sub /= 26;
            digits[j] = diff - 26 * sub;
        }
    }
    for (int j = digits.size()-1 ; j >= 0 ; j--)
    {
        cout << char('a' + digits[j]);
    }
    cout << endl;
    return 0;
}
