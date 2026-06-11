#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;
typedef tuple<int, int, int> TI;

int main()
{
    ll n,res=1;
    string s;
    cin >> n >> s;
    for(int i = 0;i<n-1;i++){
        if(s[i]!=s[i+1]){
            res++;
        }
    }
    cout << res << endl;

}
