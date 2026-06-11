#include <iostream>
#include <vector>
const int INF = 1111111111;
using namespace std;

typedef long long ll;

ll merge(vector<int>& A, int left, int mid, int right) {
    ll cnt = 0;
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L(n1+1);
    for (int i = 0; i < n1; i++) {
        L[i] = A[left+i];
    }
    L[n1] = INF;
    vector<int> R(n2+1);
    for (int i = 0; i < n2; i++) {
        R[i] = A[mid+i];
    }
    R[n2] = INF;

    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }else {
            A[k] = R[j];
            j++;
            cnt += n1 - i;
        }
    }
    return cnt;
}

ll mergeSort(vector<int>& A, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        ll v1 = mergeSort(A, left, mid);
        ll v2 = mergeSort(A, mid, right);
        ll v3 = merge(A, left, mid, right);
        return v1+v2+v3;
    }
    return 0;
}

int main(void) {
    int n;
    cin >> n;

    vector<int> ary(n);
    for (int i = 0; i < n; i++) {
        cin >> ary[i];
    }

    ll ans = mergeSort(ary, 0, n);
    cout << ans << endl;

    return 0;
}