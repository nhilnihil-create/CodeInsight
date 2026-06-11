#include <iostream>

using namespace std;

#define FS0 fs[v[0]]
#define FS1 fs[v[1]]

void rollv(int v[], int h[]) {
    int t = v[0];
    v[0] = v[1];
    v[1] = v[2];
    v[2] = v[3];
    v[3] = t;

    h[0] = v[1];
    h[2] = v[3];
}

void rollh(int v[], int h[]) {
    int t = h[0];
    h[0] = h[1];
    h[1] = h[2];
    h[2] = h[3];
    h[3] = t;

    v[1] = h[0];
    v[3] = h[2];
}

void init(int v[], int h[], int fs[]) {
    v[0] = fs[0]; v[1] = fs[1]; v[2] = fs[5]; v[3] = fs[4];
    h[0] = fs[1]; h[1] = fs[2]; h[2] = fs[4]; h[3] = fs[3];
}

int main() {
    int v[4];
    int h[4];
    int fs[6];
    int q, t, f;
    int hit;

    for (int i=0; i<6; ++i) {
        cin>>fs[i];
    }
    init(v, h, fs);

    cin>>q;

    for (int i=0; i<q; ++i) {
        cin>>t>>f;

        int h_ok = 0;
        for (int j=0; j<4; ++j) {
            int i1 = h[j];
            if (i1 == f) {
                h_ok = 1; break;
            }
        }
        if (!h_ok) {
            rollh(v, h);
        }

        for (int j=0; j<4; j++) {
            int i1 = v[0];
            if (i1 == t) { break; }
            rollv(v, h);
        }
        for (int j=0; j<4; j++) {
            int i1 = v[1];
            if (i1 == f) { break; }
            rollh(v, h);
        }

        cout<<h[1]<<endl;
    }

    return 0;
}

