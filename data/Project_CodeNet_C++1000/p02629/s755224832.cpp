#include <iostream>

using namespace std;

int main()
{
    long long N ;
    long long sumini = 1;
    long long sumend = 26;
    long long a = 26;
    int math;
    cin >> N;
    for(int i = 0;i < 20; i++)
    {
        
        if(N >= sumini && N <=sumend)
        {
            math = i+1;
            break;
        }
        sumini = sumini + a;
        a = a*26;
        sumend = sumend + a;
    }
    int iBuf[math];
    N = N - (sumini -1);
    a = a/26;
    for(int j = 0; j < math; j++)
    {
        for(int k = 0;k < 26;k++)
        {
            if(N >= k*a && N <= (k+1)*a )
            {
                iBuf[j] = k+1;
                N = N - k*a;
                a = a/26;
                break;
            }
        }
        
    }
    string alhabet = "0abcdefghijklmnopqrstuvwxyz";
    string ans(math,'a');
    for(int m = 0; m < math; m++)
    {
        ans[m] = alhabet[iBuf[m]];
    }
    cout << ans << endl;
    return 0;
}