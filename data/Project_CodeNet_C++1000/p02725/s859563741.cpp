#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    cin.sync_with_stdio( false );

    int n,k;
    cin>>k>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    vector <int> dist;
    dist.push_back(a[0] + k - a[n-1]);
    for (int i=1;i<n;i++){
        dist.push_back(a[i]-a[i-1]);
    }

    sort(dist.begin(), dist.end());
    cout<<k-dist[dist.size()-1]<<endl;
    return 0;
}
