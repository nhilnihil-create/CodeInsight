#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<array<int,2>> XL(N);
    for(int i=0;i<N;i++){
        cin >> XL[i][0] >> XL[i][1];
    }
    sort(XL.begin(), XL.end(), [](array<int,2>& a, array<int,2>& b){
        return a[0] + a[1] < b[0] + b[1];
    });
    int res = 1;
    int iprev = 0;
    for(int i=1;i<N;i++){
        if(XL[iprev][0] + XL[iprev][1] + XL[i][1] <= XL[i][0]){
            res++;
            iprev = i;
        }
    }
    cout << res << endl;

    return 0;
}