#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n;
    cin >> n;
    int arrived;
    vector<int> order(n);

    for(int i=0; i<n; i++){    
        cin >> arrived;
        order.at(arrived-1) = i;
    }

    for(int i=0; i<n; i++)
        cout << order.at(i)+1 << endl;

    return 0;
}
