#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a.at(i);
    string ans = "APPROVED";
    for(int i = 0; i < n; ++i){
        if(a.at(i) % 2 == 0){
            if(a.at(i) % 3 == 0 || a.at(i) % 5 == 0) continue;
            else ans = "DENIED";
        }
    }    
    cout << ans << endl;
    return 0;
}