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
    ll n;
    cin >> n;
    int input[n];
    rep0(i,n)
    {
        cin >> input[i];
    }
    int now=input[0];
    bool res = true;
    rep0(i,n)
    {
        if(now>input[i]){
            res = false;
            break;
        }
        now=max(input[i]-1,now);
    }
    if(res){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
        

}
