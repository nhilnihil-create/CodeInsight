#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    int N;
    string S;
    cin >> N;
    cin >> S;
    int result = 0;
    for(int num = 0; num <= 999; num++)
    {
        int num1 = num / 100;
        int num2 = num / 10 - num1 * 10;
        int num3 = num % 10;
        int p1 = -1;
        int p2 = -1;
        int p3 = -1;
        for(int i = 0; i < N; i++)
        {
            if(S[i] - '0' == num1)
            {
                p1 = i;
                break;
            }
        }
        if(p1 == -1)
        {
            continue;
        }
        for(int i = p1 + 1; i < N; i++)
        {
            if(S[i] - '0' == num2)
            {
                p2 = i;
                break;
            }
        }
        if(p2 == -1)
        {
            continue;
        }
        for(int i = p2 + 1; i < N; i++)
        {
            if(S[i] - '0' == num3)
            {
                p3 = i;
                break;
            }
        }
        if(p3 == -1)
        {
            continue;
        }
        result++;
    }
    cout << result << endl;
    return 0;
}