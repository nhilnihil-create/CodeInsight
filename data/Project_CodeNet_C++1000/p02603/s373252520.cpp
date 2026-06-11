#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    int a[80];
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> days;
    int low = a[0], high;
    bool isLowSearching = true;
    for(int i = 1; i < n; i++){
        if(isLowSearching){
            // 低いときを探して買って
            if(a[i] <= low) low = a[i];
            else{
                isLowSearching = false;
                high = a[i];
            }
        }
        if(!isLowSearching){
            // 高いときを探して売る
            if(a[i] < high || i == n - 1){
                days.push_back(low);
                days.push_back(high);
                isLowSearching = true;
                low = a[i];
            }else{
                high = a[i]; //a[i] >= high
            }
        }

    }

    long long int ans = 1000, stock = 0;
    for(int i = 0; i < days.size(); i += 2){
        stock = ans / days[i];
        ans = ans % days[i] + days[i + 1] * stock;
    }

    cout << ans << endl;
    return 0;
}