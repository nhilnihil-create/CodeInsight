#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() {
    SPEED;
    int arr[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (arr[j][k] == temp) {
                    arr[j][k] = -1;
                }
            }
        }
    }

    int flag = 0;
    if ((arr[0][0] == -1 && arr[0][1] == -1 && arr[0][2] == -1) ||
        (arr[1][0] == -1 && arr[1][1] == -1 && arr[1][2] == -1) ||
        (arr[2][0] == -1 && arr[2][1] == -1 && arr[2][2] == -1) ||
        (arr[0][0] == -1 && arr[1][0] == -1 && arr[2][0] == -1) ||
        (arr[0][1] == -1 && arr[1][1] == -1 && arr[2][1] == -1) ||
        (arr[0][2] == -1 && arr[1][2] == -1 && arr[2][2] == -1) ||
        (arr[0][0] == -1 && arr[1][1] == -1 && arr[2][2] == -1) ||
        (arr[0][2] == -1 && arr[1][1] == -1 && arr[2][0] == -1)) {
            flag = 1;
        }

        if (flag == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

    return 0;
}