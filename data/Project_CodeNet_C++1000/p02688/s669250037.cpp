#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n,k,x, b;
    map <int, int>cnt;
    cin >> n >> k;
    for(int i=1; i<=k; i++){
        cin >> x;
        for(int j=0; j<x; j++){
            cin >> b;
            cnt[b]++;
        }
    }
    cout << n - cnt.size();
    return 0;
}
