#include<bits/stdc++.h>

using namespace std;

int main(void) {
    long n;
    cin >> n;

    vector<long> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;

    long c = 0, r = 0;
    for(int i=0; i<n; i++)
        if(a[i] == b[i]) c++;

    set<long> s;
    for(int i=0; i<n; i++)
        if(a[i] != b[i] && b[i] > b[(i-1+n)%n] + b[(i+1)%n])
            s.insert(i);

    while(!s.empty()) {
        long i = *s.begin(); s.erase(i);
        long ai = (i-1+n)%n, bi = i%n, ci = (i+1)%n;

        if(a[i] == b[i]) continue;
        if(b[bi] <= b[ai] + b[ci]) continue;
        if((b[i] - a[i]) / (b[ai] + b[ci]) == 0) continue;

        r += (b[i] - a[i]) / (b[ai] + b[ci]);
        b[i] = a[i] + ((b[i] - a[i]) % (b[ai] + b[ci]));

        if(b[ai] > b[bi] + b[(ai-1+n)%n]) s.insert(ai);
        if(b[ci] > b[bi] + b[(ci+1+n)%n]) s.insert(ci);

        if(a[i] == b[i]) {
            c++;
            continue;
        }
        if(b[bi] > b[ai] + b[ci]) s.insert(bi);
    }

    cout << (c == n ? r : -1) << endl;
}
