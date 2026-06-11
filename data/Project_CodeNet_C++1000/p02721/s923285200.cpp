#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int INF = 1 << 30;
int main()
{
    int N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;
    // 左から貪欲
    vector<int> L; // i+1回目に働く日
    for(int i = 0; i < N;)
    {
        if (S[i] == 'o')
        {
            L.push_back(i);
            i += C + 1; // C 日間空ける
        }
        else
        {
            ++i; // 次の日を見る
        }
        
    }
    if (L.size() > K) return 0;
    L.push_back(N);
    // 右から貪欲
    vector<int> R(K+1);
    R[K] = INF;
    for (int i = K-1; i >= 0; --i)
    {
        for (int l = L[i + 1] - 1; l >= L[i]; --l)
        {
            if (S[l] == 'o' && l + C < R[i + 1])
            {
                R[i] = l;
                break;
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < K; ++i)
    {
        if  (L[i] == R[i]) ans.push_back(L[i]);
    }
    if (ans.size() == 0) return 0;
    for (auto a : ans)
    {
        cout << a + 1 << endl;
    }
    return 0;
}
