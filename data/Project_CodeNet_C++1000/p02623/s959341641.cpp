#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include <string.h>
using namespace std;

#define MAX 200000
long long sum_A[MAX], sum_B[MAX];

int binarySearch(long long l[], int n, int key) {
    int left = 0;
    int right = n;
    int mid;
    while ( left < right ) {
        mid = (left + right) / 2;
        if ( key == l[mid] ) {
            return mid + 1;
        }
        if ( key > l[mid] ) {
            left = mid + 1;
            if ( right == left ) {
                return right;
            }
        } else if ( key < l[mid] ) {
            right = mid;
            if ( right == left ) {
                return right;
            }
        }
    }
    return 0;
}

int main() {
    int N, M, K, tmp;
    int idx;
    int w_ans = 0, ans = 0;
    
    cin >> N >> M >> K;
    for ( int ii = 0; ii < N; ii++ ) {
        cin >> tmp;
        if ( ii == 0 ) {
            sum_A[ii] = tmp;
        } else {
            sum_A[ii] = sum_A[ii - 1] + tmp;
        }
    }
    for ( int ii = 0; ii < M; ii++ ) {
        cin >> tmp;
        if ( ii == 0 ) {
            sum_B[ii] = tmp;
        } else {
            sum_B[ii] = sum_B[ii - 1] + tmp;
        }
    }
    
    idx = binarySearch(sum_A, N, K);
    if ( idx == 0 ) {
        tmp = K;
    } else {
        tmp = K - sum_A[idx - 1];
    }
    ans = w_ans = idx;
    
    while ( 1 ) {
        int tmp_idx = binarySearch(sum_B, M, tmp);
        w_ans += tmp_idx;
        if ( w_ans > ans ) {
            ans = w_ans;
        }
        idx--;
        if ( idx < 0 ) {
            break;
        }
        if ( idx == 0 ) {
            tmp = K;
        } else {
            tmp = K - sum_A[idx - 1];
        }
        w_ans = idx;
    }
    
    
    cout << ans << endl;
    return 0;
}