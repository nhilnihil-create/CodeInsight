#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,n,i;
    cin >> x >> n;

    vector<int> p(n);
    for(i=0; i<n; i++)
    cin >> p.at(i);

    int ans =0;
    for(int q=0; q<=101; q++){
        int f= 1;
        for(i=0; i<n; i++){
            if(q == p.at(i)){
                f = 0;
            }
        }

        if(f==0){
            continue;
        }
        if(abs(ans - x) > abs(q-x)){
            ans = q;
        }
    }
    cout << ans << endl;
    return 0;
}