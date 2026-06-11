#include <bits/stdc++.h>
using namespace std;

vector<long long> divide(string S)
{
    vector<long long> t;
    char tempS = S[0];
    long long temp = 0;
    for(int i = 0;i<S.size();i++)
    {
        if(S[i] == tempS)
        {
            temp++;
        }
        else
        {
            t.push_back(temp);
            temp = 1;
            tempS = S[i];
        }
    }
    t.push_back(temp);
    
    return t;
}

long long turn(long long x)
{
    return x/2;
}

int main()
{
    string S;
    cin >> S;
    long long K;
    cin >> K;
    
    //先頭と最後が同じ
    
    vector<long long> val = divide(S);
    int len = (int)S.size();
    int N = (int)val.size();
    long long ans = 0;
    if(S[0] == S[len-1])
    {
        //文字一つだけ
        if(N == 1)
        {
            ans = turn(val[0] * K);
        }
        else
        {
            //先頭 1
            ans += turn(val[0]);
            //ワードの中身 *K
            for(int i = 1;i<N-1;i++)
            {
                ans += turn(val[i]) * K;
            }
            //接続部分 *(K-1)
            ans += turn(val[0] + val[N-1]) * (K-1);
            //ラスト 1
            ans += turn(val[N-1]);

        }
    }
    //それ以外
    else
    {
       //ワードの中身 *K
        for(int i = 0;i<N;i++)
        {
            ans += turn(val[i]) * K;
        }
    }
    
    cout << ans << endl;
    //cout << K << endl;
    
   
    
    return 0;
}