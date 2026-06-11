#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    int ans = 0;
    for (int i=0; i<1000; i++)
    {
        int nums[3] = {i/100%10, i/10%10, i%10};
        int k=0;
        bool pos=false;
        for (int p=0; p<S.length(); p++)
        {
            if (S[p]-'0'==nums[k])
            {
                k++;
            }
            if (k==3)
            {
                pos=true;
                break;
            }
        }
        if (pos) ans++;
    }
    cout << ans << endl;
}