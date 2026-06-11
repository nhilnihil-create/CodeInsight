#include <bits/stdc++.h>

#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define FILL0(x) memset(x,0,sizeof(x))
#define FILL1(x) memset(x,-1,sizeof(x))

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    bool nprime[n]={false};
    vector<int> a(1000010);
    
    rep(i, n)
    {
        int val;
        cin >> val;
        a[val]++;
    }
    bool f =false;
    int uprime[1000001]={0};
    int aa[1000001]={0};
    for(int i=2; i<1000001; i++)
    {
        if(uprime[i]==0)
        {
            for(int j=0; i+i*j<1000001; j++)
            {
                uprime[i+i*j]=1;
                aa[i]+=a[i+i*j];
            }
            if(aa[i]>1)
            {
                f=true;
            }
            if(aa[i]==n)
            {
                cout << "not coprime" << endl;
                return 0;
            }
        }
    }

    if(f)
    {
        cout << "setwise coprime" << endl;
    }
    else
    {
        cout << "pairwise coprime" << endl;
    }
    
 
    return 0;
}