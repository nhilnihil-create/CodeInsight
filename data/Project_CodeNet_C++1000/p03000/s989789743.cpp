#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,x,i,d=0,cnt=1;
    cin >> n >> x;

    for(i=0; i<n; i++){
        int l;
        cin >> l;
        d += l;
        if(d <= x)
            cnt++;
        else
            break;
    }

    cout << cnt << endl;
    return 0;
}