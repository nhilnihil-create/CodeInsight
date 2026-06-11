#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
int main()
{
    int n,k;cin >> n >> k;
    vector<int> a(n);
    rep(i,n)
    {
        cin >> a[i];
    }
    int left, right, mid;
    left = 0;
    right = *max_element(all(a));
    mid = (left+right)/2;
    while(right-left>1)
    {
        //cout << mid << endl;
        int counter =0;
        rep(i,n)
        {
            counter += ceil((double)a[i]/(double)mid)-1;
        }
        if(counter>k)
        {
            left = mid;
        }else{
            right = mid;
        }
        mid = (right+left)/2;
    }
    cout << right << endl;

}