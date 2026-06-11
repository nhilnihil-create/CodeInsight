#include <iostream>
using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int d[6];
    for (int i = 0; i < 6; i++) {
        cin >> d[i];
    }
    int q, tp, ft;
    cin >> q;
    while (0 < q) {
        cin >> tp >> ft;
        int i, j;
        for (i = 0; i < 6; i++)
            if (d[i] == tp)
                break;
        for (j = 0; j < 6; j++)
            if (d[j] == ft)
                break;
        
        if (i < 3 && j < 3)
            if (i < j)
                if (j-i==1)
                    cout << d[3-i-j] << "\n";
                else
                    cout << d[5-(3-i-j)] << "\n";
            else
                if (i-j==1)
                    cout << d[5-(3-i-j)] << "\n";
                else
                    cout << d[3-i-j] << "\n";
        else if (2 < i && 2 < j)
            if (i < j)
                if (j-i==1)
                    cout << d[12-i-j] << "\n";
                else
                    cout << d[5-(12-i-j)] << "\n";
            else
                if (i-j==1)
                    cout << d[5-(12-i-j)] << "\n";
                else
                    cout << d[12-i-j] << "\n";
        else if (2 < j) {
            int k = 5-j;
            if (i < k)
                if (k-i==1)
                    cout << d[5-(3-i-k)] << "\n";
                else
                    cout << d[3-i-k] << "\n";
            else
                if (i-k==1)
                    cout << d[3-i-k] << "\n";
                else
                    cout << d[5-(3-i-k)] << "\n";
        }
        else if (2 < i) {
            int k = 5-i;
            if (k < j)
                if (j-k==1)
                    cout << d[5-(3-j-k)] << "\n";
                else
                    cout << d[3-j-k] << "\n";
            else
                if (k-j==1)
                    cout << d[3-j-k] << "\n";
                else
                    cout << d[5-(3-j-k)] << "\n";
        }
        q--;
    }
}