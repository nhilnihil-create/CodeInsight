#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)

int N;
int A[1000010];
int D[1000010];
int mem[1000010];
bool f;

int GCD(int a, int b)
{
    if(a % b == 0)return b;
    return GCD(b, a % b);
}

signed main()
{
    cin >> N;
    rep(i, N)cin >> A[i];

    for(int i = 2; i < 1000010; i++)
    {
        if(D[i] == 0)
        {
            for(int j = 1; j * i < 1000010; j++)D[i * j] = i;
        }
    }
    D[1] = 1;

    rep(i, N)
    {
        if(A[i] == 1)continue;
        int tmp = A[i];
        int now;
        while(D[tmp] != tmp)
        {
            now = D[tmp];
            if(mem[now] && mem[now] != i + 1)f = true;
            mem[now] = i + 1;
            tmp = tmp / D[tmp];
        }
        if(mem[tmp] && mem[tmp] != i + 1)f = true;
        mem[tmp] = i + 1;
    }

    if(f)
    {
        int gcd = GCD(A[0], A[1]);
        rep(i, N)gcd = GCD(gcd, A[i]);
        if(gcd == 1)
        {
            cout << "setwise coprime" << endl;
        }
        else cout << "not coprime" << endl;
        return 0;
    }

    cout << "pairwise coprime" << endl;

    return 0;
}
