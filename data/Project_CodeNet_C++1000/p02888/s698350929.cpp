#include <bits/stdc++.h>
using namespace std;
static const int MAX = 2000;
static const int NIL = 1001;

int N;
vector<int> A(MAX,NIL);

int binarysearch(int x,int y){
    int left = y;
    int right = N;
    while (left + 1 < right) {
        int mid = (left + right)/2;
        if (A.at(mid) >= A.at(x) + A.at(y)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    //cout << right << endl;
    return right - y - 1;
}

int main() {
    cin >> N;
    
    for (int i=0;i<N;i++){
        cin >> A.at(i);
    }
    sort(A.begin(),A.end());
    int cnt=0;
    for(int i=0;i<N-2;i++) {
        for(int j=i+1;j<N-1;j++) {
            cnt += binarysearch(i,j);
        }
    }
    cout << cnt << endl;
}