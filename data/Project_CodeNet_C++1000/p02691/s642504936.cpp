#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
map<long long,int>mm;
int main()
{
    long long num;
    int n;
    cin >> n;
    long long ans =0 ;
    for(long long i=0;i<n;i++){
        cin >> num ;
        ans += mm[i-num];
        mm[i+num]++;
    }
    cout << ans << endl;
    return 0;
}
