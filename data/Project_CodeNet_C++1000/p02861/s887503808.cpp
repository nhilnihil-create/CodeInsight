#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
using ll = long long;

int main(){
	int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(2));
    int x;
    int y;
    vector<int> order;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        v.at(i).at(0) = x;
        v.at(i).at(1) = y;
        order.push_back(i);
    }

    double sum = 0.0;
    double count = 0.0;
    do{
        for(int i = 1; i < n; i++){
            int prev = order.at(i - 1);
            int now = order.at(i);
            int x0 = v.at(prev).at(0);
            int y0 = v.at(prev).at(1);
            int x1 = v.at(now).at(0);
            int y1 = v.at(now).at(1);
            sum += sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
        }
        count++;
    }while(next_permutation(order.begin(), order.end()));

    double ans = sum / count;
    cout << setprecision(15) << ans << endl;
  	return 0;
}
