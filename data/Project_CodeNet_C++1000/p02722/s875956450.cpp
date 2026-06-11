#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin >> n;

    vector<long long int> div1;
    for (long long int i=1; i*i<=n-1; i++){
        if ((n-1) % i == 0){
            div1.push_back(i);

            long long int j = (n-1) / i;
            if (j != i) div1.push_back(j);
        }
    }
    long long int ans = div1.size() - 1;
    vector<long long int> div2;
    for (long long int i=2; i*i<=n; i++){
        if (n % i == 0) div2.push_back(i);
    }

    int m = div2.size();
    for(int i=0; i<m; i++){
        long long int a = n;
        while(a > 0){
            if(a % div2[i] == 0) a /= div2[i];
            else break;
        }
        if(a % div2[i] == 1) ans += 1;
    }
    ans += 1;// self
    cout << ans << endl;
    return 0;
}
