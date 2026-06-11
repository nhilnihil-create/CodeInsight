#include <bits/stdc++.h>
#define nmax 1<<19
using namespace std;
int n,v[nmax];
bool viz[nmax];
vector <int> a;

int main() 
{

    cin >> n;
    for (int i = 0; i < (1 << n); i++)
        cin >> v[i];

    sort(v, v + (1 << n));
    reverse(v, v + (1 << n));

    a.push_back(v[0]);
    viz[0] = 1;
    for (int i = 0; i < n; i++) {
        int k = 1;
        for (int j = 0; j < (1 << i); j++) {

            while (k < (1 << n) && (v[k] >= a[j] || viz[k]))
                k++;

            if (k == (1 << n)) {
                cout << "No";
                return 0;
            }
            viz[k] = 1;
            a.push_back(v[k]);
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
    }
    cout << "Yes";

    return 0;
}