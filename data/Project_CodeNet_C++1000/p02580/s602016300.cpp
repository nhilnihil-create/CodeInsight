#include <iostream>
using namespace std;
int x[300006];
int y[300006];
int a[300006];
int b[300006];
int main () {
    int h, w, m;
    cin >> h >> w >> m;
    for (int i=0; i<m; i++) {
        int c, d;
        cin >> c >> d;
        x[c]++;
        y[d]++;
        a[i]=c;
        b[i]=d;
    }
    int mxx=0, mxy=0;
    for (int i=0; i<=300000; i++) {
        mxx=max(mxx, x[i]);
        mxy=max(mxy, y[i]);
    }
    int xn=0, yn=0;
    for (int i=0; i<=300000; i++) {
        if (x[i]==mxx) {
            xn++;
        }
        if (y[i]==mxy) {
            yn++;
        }
    }
    int sum=0;
    for (int i=0; i<m; i++) {
        if (x[a[i]]==mxx && y[b[i]]==mxy) {
            sum++;
        }
    }
    if (sum==xn*yn) {
        cout << mxx+mxy-1 << endl;
    }
    else {
        cout << mxx+mxy << endl;
    }
}