#include<bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), r = b.size(),ans = r, pc;
    for(int i=0; i<=n-r; i++){
        pc=0;
        for(int k=0,j=i; k<r; k++, j++)
            if(a[j]!=b[k]) pc++;

        ans = min(ans, pc);
    }
    cout<<ans<<endl;

    return 0;
}
