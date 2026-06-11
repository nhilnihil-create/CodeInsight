#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n; cin >> n;
    long long k; cin >> k;
    vector<int> a(n);
    int _a;
    for (int i = 0; i < n; i++) 
    {
        cin >> _a; a[i] = _a - 1;
    }
    vector<int> tr(n, -1);
    int s = 0;
    int t = 0;
    while (tr[s] < 0)
    {
        tr[s] = t; 
        t++;
        s = a[s];
    }
    int loop_start = tr[s];
    int loop_size = (t - tr[s]);
    long long tar;
    if (k < (long long)loop_start) tar = k;
    else tar = (long long)loop_start + (k - (long long) loop_start) % (long long)loop_size;
    s = 0;
    for (long long t = 0; t < tar; t++) s = a[s];
    cout << s + 1 << endl;
}