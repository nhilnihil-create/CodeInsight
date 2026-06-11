#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,i,step=0;
    cin >> n;

    long a[n];
    cin >> a[0];
    for(i=1; i<n; i++){
        cin >> a[i];
        if(a[i] < a[i-1]){
            step += a[i-1]-a[i];
            a[i] += a[i-1]-a[i]; 
        }

    }
    
    cout << step << endl;
}