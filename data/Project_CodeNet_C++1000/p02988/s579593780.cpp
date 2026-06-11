#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> ns;
    int n = 0, count = 0;

    cin >> n;

    while(n--) {
        int t = 0;
        cin >> t;
        ns.push_back(t);
    }

    for (int i = 1; i < ns.size()-1; i++) {
        if (ns[i] < ns[i+1] && ns[i] > ns[i-1] || ns[i] > ns[i+1] && ns[i] < ns[i-1])
            count++;
    }

    cout << count << endl;

    return 0;
}
