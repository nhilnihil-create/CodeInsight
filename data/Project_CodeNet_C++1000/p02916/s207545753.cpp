#include<bits/stdc++.h>
#define fasterthanlight ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define test int T; cin>>T; while(T--)
#define endl "\n"
#define int long long
#define vi vector<int>
#define pb push_back
#define mod 1000000007
#define MAX 1e9
#define MIN -1e9
#define hi "visited\n" //sasta debugging
using namespace std;

//author::@whohet-->Het Patel

signed main()
{
    fasterthanlight;
    int n;
    cin >> n;
    int arr[n][2];
    for (int i = 0; i < n; i++)
        cin >> arr[i][0];
    for (int i = 0; i < n; i++)
        cin >> arr[i][1];
    int c[n - 1];
    for (int i = 1; i < n; i++)
    {
        cin >> c[i - 1];
    }
    int sum = 0; int prev = -2;
    for (int i = 0; i < n; i++)
    {
        //cout << arr[i][0]

        if (arr[i][0] == prev + 1)
            sum += (arr[arr[i][0] - 1][1]) + c[prev - 1];
        else
            sum += (arr[arr[i][0] - 1][1]);
        prev = arr[i][0];
        //  cout << prev<<" " << endl;
    }
    cout << sum << endl;
    //cout << "\n\n"<<"Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " seconds.\n";
    return 0;
}
