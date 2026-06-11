#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i )
typedef std::pair<int,int> pint;

using namespace std;
typedef long long ll;

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> list(N);
    int max = 0;
    rep (i,N){
        cin >> list[i];
        if (list[i] > max){
            max = list[i];
        }
    }
    int left = 0; int right = max;
    while ((right - left) > 1){
        int mid = (right + left)/2;
        int count = 0;
        rep (i,N){
                count += (list[i] - 1)/mid;
        }
        if (count <= K){
            right = mid;
        }
        else {
            left = mid;
        }
    }
    cout << right << endl;
    return 0;
}