#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<vector<int> > cnt;
    cnt.resize(N);
    string str;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        cnt[i].resize(26);
        fill(cnt[i].begin(), cnt[i].end(), 0);
        for (char c : str)
        {
            cnt[i][c - 'a']++;
        }
        
    }

    sort(cnt.begin(), cnt.end());

    long long ans = 0;
    vector<int> prv = cnt[0];
    long long n = 0;
    for (int i = 1; i < N; i++)
    {
        if (prv == cnt[i])
        {
            n++;
        }else
        {
            if (n == 0)
            {
            }else
            {
                ans += (n + 1) * n / 2;
                n = 0;
            }
            
        }
        prv = cnt[i];
        
    }

    if (n != 0)
    {
       ans += (n + 1) * n / 2;
    }
    
    
    cout << ans << endl;
    
    return 0;
}