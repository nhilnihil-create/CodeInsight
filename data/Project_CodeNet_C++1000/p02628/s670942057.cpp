#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int k,n,a;
    vector <int> prices;
    cin >> n;
    if(1>n || n > 1000)
        return 0;
    cin >> k;
    if(1>k || k>1000)
        return 0;
    for(int i=0;i<n;i++){
        cin >> a;
        if(1>a || a>1000)
            return 0;
        prices.push_back(a);

    }
    int minindex=0,total=0;
    for(int i=0;i<k;i++){
        total = total + *min_element(prices.begin(),prices.end());
        minindex = min_element(prices.begin(),prices.end()) - prices.begin();
        prices[minindex] = 10001;
    }
    cout << total;
    return 0;
}
