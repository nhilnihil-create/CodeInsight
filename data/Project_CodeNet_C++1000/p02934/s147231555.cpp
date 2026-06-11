#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    long double ans=0;
    for(int i=0;i<n;i++){
        long double a;
        cin >> a;
        ans+=1/a;
    }
    cout << 1/ans << endl;
}