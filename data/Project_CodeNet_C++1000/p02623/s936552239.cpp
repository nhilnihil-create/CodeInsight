#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/* int floorSearch(int arr[], int low,
                int high, int x)
{
    // If low and high cross each other
    if (low > high)
        return -1;

    // If last element is smaller than x
    if (x >= arr[high])
        return high;

    // Find the middle point
    int mid = (low + high) / 2;

    // If middle point is floor.
    if (arr[mid] == x)
        return mid;

    // If x lies between mid-1 and mid
    if (mid > 0 && arr[mid - 1] <= x
        && x < arr[mid])
        return mid - 1;

    // If x is smaller than mid, floor
    // must be in left half.
    if (x < arr[mid])
        return floorSearch(
            arr, low, mid - 1, x);

    // If mid-1 is not floor and x is
    // greater than arr[mid],
    return floorSearch(arr, mid + 1, high, x);
} */
int main()
{
    int n, m, k, csum, temp, cntr, maxc, temp2, index;
    cin >> n;
    cin >> m;
    cin >> k;
    csum = 0;
    vector<int> a;
    vector<int> b;
    for ( int i = 0; i < n; i ++) {
        cin >> temp2;
        temp = csum + temp2;
        if ( temp <= k && temp > 0){
            a.push_back(temp);
            csum = temp;
        }
        else break;
    }
    if ( ! (n == a.size()) ){
        for ( int i = 0; i < n - a.size() - 1; i++) cin >> temp2;
    }
    csum = 0;
    for ( int i = 0; i < m; i++) {
        cin >> temp2;
        temp = csum + temp2;
        if ( temp <= k && temp > 0){
            b.push_back(temp);
            csum = temp;
        }
        else break;
    }
    if ( ! (m == b.size()) ) {
        for ( int i = 0; i < m - b.size() - 1; i++) cin >> temp2;
    }
    maxc = b.size();
    for ( int i = 0; i < a.size(); i++) {
        auto it = lower_bound(b.begin(), b.end(), k - a[i]);
        index = it - b.begin();
        if ( it != b.end() && (*it > k - a[i])) index--;
        if ( it == b.end() ) cntr = b.size() + i + 1;
        else cntr = index + 1 + i + 1;
        if ( cntr > maxc ) maxc = cntr;
    }
    cout << maxc;
    return 0;
}