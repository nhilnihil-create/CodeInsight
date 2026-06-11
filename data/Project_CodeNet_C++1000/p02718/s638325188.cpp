#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define int long long int
#define vi vector<int>
#define vvi vector < vi >
#define pii pair<int,int>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define tr(k,st,en) for(int k = st; k <= en ; k++)

using namespace std;

int32_t main()
{
    std::ios::sync_with_stdio(false);
    int n,m, sum = 0;
    cin>>n>>m;
    vector<int> arr(n);
    tr(i,0,n-1){
        cin>>arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end(),greater<>());
    int i = 0,cnt = 0;
    if(sum % (4*m) == 0){
        sum /= (4*m);
    } else {
        sum /= (4*m);
        sum++;
    }
    while (i < arr.size()) {
        if (arr[i] >= sum) {
            cnt++;
        }
        i++;
    }
    if (cnt >= m) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
    return 0;
}

