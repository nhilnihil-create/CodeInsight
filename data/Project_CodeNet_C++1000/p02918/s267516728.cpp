#include <bits/stdc++.h>

#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
#define FILL0(x) memset(x,0,sizeof(x))

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    int happy=0;
    rep(i, N)
    {
        if(S[i]=='L')
        {
            if(i!=0&&S[i-1]=='L')
            {
                happy++;
            }
        }

        if(S[i]=='R')
        {
            if(i!=N-1&&S[i+1]=='R')
            {
                happy++;
            }
        }
    }

  
    happy+=2*K;
  
    
    if(happy>N-1)
    {
        cout << N-1 << endl;
    }
    else
    {
        cout << happy << endl;
    }
    
    

 

 

 

    return 0;
}
