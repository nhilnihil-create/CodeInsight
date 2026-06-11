#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    int d[N];
    for(int i=0;i<N;i++) {
        cin >> d[i];
    }
    sort(d,d+N); 
    int mid = N/2;
    int ans = d[mid] - d[mid-1];
    cout << ans << endl;
    return 0;

}
