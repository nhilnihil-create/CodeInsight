#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=-118;i<=119;i++){
        for(int j=-119;j<=118;j++){
            long long int x = pow(i,5);
            long long int y = pow(j,5);
            if(x-y==n){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
}
