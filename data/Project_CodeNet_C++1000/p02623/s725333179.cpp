#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<pii> vii;

#define rep(x,n) for (int i = x; i < (n); ++i)
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define fr first
#define sc second
#define Fast_IO ios::sync_with_stdio(false) ,cin.tie(0) ,cout.tie(0)

int binarySearch(long long a[], int beg, int end, int item)
{
    int mid;
    if(end >= beg)
    {
        mid = (beg + end)/2;

        if(a[mid] == item)
            return mid+1;
        else if(a[mid] < item)
        {
            if (a[mid+1] == item)
                return mid+2;
            else if (a[mid+1] > item)
                return mid+1;
            else
                return (binarySearch(a,mid+1,end,item));
        }
        else
        {
            if (a[mid-1] < item)
                return mid;
            else if(a[mid-1] == item)
                return mid;
            else
                return binarySearch(a,beg,mid-1,item);
        }
    }
    return beg;
}

int main()
{
    Fast_IO;
    int n ,m ,k;
    cin >> n >> m >> k;
    ll arr1[n] ,arr2[m] ,pfx2[m+1]={0};

    rep(0 ,n) cin >> arr1[i];
    rep(0 ,m) cin >> arr2[i];
    pfx2[0] = arr2[0];
    rep(1 ,m) pfx2[i] = pfx2[i-1]+arr2[i];
    pfx2[m] = LONG_LONG_MAX;
    int i = 0 ,res = (k < pfx2[0]) ? 0 :binarySearch(pfx2 ,0 ,m ,k);
    while(i<n && k-arr1[i] >= 0)
    {
        int temp = i+1;
        k -= arr1[i++];
        temp += binarySearch(pfx2 ,0 ,m ,k);
        res = max (res , temp);
    }
    cout << res;
    return 0;
}