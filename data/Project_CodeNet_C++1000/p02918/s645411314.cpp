#include <iostream>
#include <string>

using namespace std;
string s;

void revert(int begin, int end)
{
    for (int i = end; i <= begin; i++)
    {
        if (s[i] == 'L')
            s[i] = 'R';
        else
            s[i] = 'L';
    }
}

void cal(int N, int *K, int *num)
{
    int f_begin, begin, end;
    f_begin = begin = N - 2;
    while ((*K) > 0 && f_begin > 0)
    {
        for (; begin > 0 && s[begin] == s[N - 1]; begin--)
            ;
        for (end = begin - 1; end > 0 && s[end] != s[begin]; end--)
            ;
        for (; end > 0 && s[end] == s[begin] && s[end - 1] == s[begin]; end--)
            ;

        if (end > 0)
        {
            revert(begin, end);
            (*K)--;
            begin = end - 2;
        }
        else
        {
            for (f_begin = f_begin - 1; f_begin > 0 && s[f_begin] == s[N - 1]; f_begin--)
                ;
            begin = f_begin;
        }
    }
}

int main()
{
    int N, K, num = 0;
    char t;

    cin >> N >> K;
    cin >> s;

    cal(N, &K, &num);

    if (N > 1)
    {
        if (K > 0 && s[1] == s[N - 1])
        {
            for (int i = 2; i < N; i++)
                if (s[i] != s[N - 1])
                {
                    s[i] = s[N - 1];
                    K--;
                    break;
                }
        }
        if (K > 0 && s[0] != s[N - 1])
        {
            int i;
            for (i = 1; s[i] == s[0]; i++)
                ;
            revert(i - 1, 0);
            K--;
        }
        if (K > 0 && s[1] != s[N - 1])
        {
            s[1] = s[N - 1];
            K--;
        }
    }

    for (int i = 0; i < N - 1; i++)
    {
        if (s[i + 1] == s[i])
            num++;
    }

    cout<< num << endl;

    return 0;
}