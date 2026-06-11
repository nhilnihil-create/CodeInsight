#include <iostream>
#include <set>

using namespace std;
multiset < int > s;
int main()
{
    int n, k, price, sum;
    cin >> n;
    cin >> k;
    sum = 0;
    for ( int i = 0; i < n; i++){
        cin >> price;
        s.insert(price);
    }
    for ( int i = 0; i < k; i++) {
        sum += *s.begin();
        s.erase(s.begin());
    }
    cout << sum << endl;
}
