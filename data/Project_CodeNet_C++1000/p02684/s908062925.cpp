#include <iostream>
#include <vector>

using namespace std;
const int N = 2e5 + 1;
long long k;
int n,a[N];
bool avail[N];
vector <int> V;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    V.push_back(0);
    int start = 1; bool run = false;
    while (avail[a[start]] == false){
        start = a[start];
        avail[start] = true;
        V.push_back(start);
    }
    //V.push_back(a[start]);
    //for (int i = 1; i < V.size(); i++) cout << V[i] << " "; cout << "\n";
    int d , c = V.size() - 1;
    for (int i = 1; i < V.size(); i++)
        if (a[start] == V[i]) d = i;
    //cout << d << " " << c << "\n";
    if (k < d) cout << V[k];
    else{
        k = k - d + 1;
        k = k % (c - d + 1);
        if (k == 0) cout << V[c];
        else cout << V[d + k - 1];
    }
    return 0;
}
