#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repe(i,a,b) for(ll i=a;i>=b;i--)

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ll long long
#define ld long double

#define V vector<ll>
#define pp pair<ll,ll>
#define pb push_back
#define mp make_pair
#define Pr pair<ll,ll>
#define all(A) A.begin(),A.end()
#define allr(A) A.rbegin().A.rend()

#define ff first
#define ss second
#define len length()
ll max3(ll a,ll b,ll c)
{
    if(a>=b&&a>=c)
        return a;
    else if(b>=a&&b>=c)
        return b;
    else
        return c;
}
int min3(int a,int b,int c)
{
    if(a<=b&&a<=c)
        return a;
    else if(b<=a&&b<=c)
        return b;
    else
        return c;
}
int binarySearch(ll arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);


        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}
int main()
{
	fast;

           int a;
           cin>>a;
           string s;
           cin>>s;
           if(a<3200)
            cout<<"red"<<endl;
           else
            cout<<s<<endl;

    return 0;
}
