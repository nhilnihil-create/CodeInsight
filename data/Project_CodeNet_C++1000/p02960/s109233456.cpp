#include <bits/stdc++.h>

#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
#define FILL0(x) memset(x,0,sizeof(x))

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
 const ll MOD = ll(1e9) +7;
ll dp[2][13];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    string S;
    cin >> S;

    rep(i, S.size())
    {
        FILL0(dp[(i+1)%2]);

        if(i==0)
        {
            if(S[i]!='?')
            {
                dp[(i+1)%2][(S[i]-'0')%13]=1;
            }
            else
            {
                rep(k, 10)
                {
                    dp[(i+1)%2][k%13]=1;
                }
            }
            continue;
        }

        rep(j, 13)
        {
            if(S[i]!='?')
            {
                dp[(i+1)%2][(j*10+S[i]-'0')%13]+=dp[i%2][j];  //13sinnsuu
                dp[(i+1)%2][(j*10+S[i]-'0')%13]%=MOD;
            }
            else
            {
                rep(k, 10)
                {
                    dp[(i+1)%2][(j*10+k)%13]+=dp[i%2][j];
                    dp[(i+1)%2][(j*10+k)%13]%=MOD;
                }
            }
            
        }
    }
    
    cout << dp[S.size()%2][5] << endl;

 

 

    return 0;
}
 

//cout << setprecision(13);
//next_permutation();
//__gcd();
//reverse();
//set ,tuple ,pair;
//bitset
//vector.find

