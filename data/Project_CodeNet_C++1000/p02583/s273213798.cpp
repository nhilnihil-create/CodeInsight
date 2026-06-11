#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;

int main(void){
    int n, cnt = 0;
    cin >> n;
    vi L(n);
    for(int &l : L) cin >> l;
    if(n < 3) goto SKIP;
    sort(L.begin(), L.end());
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            if(L[i] == L[j]) continue;
            for(int k=j+1; k<n; k++){
                if(L[j] == L[k]) continue;
                if(L[k] == L[i]) continue;
                if(L[k]<L[i]+L[j]) cnt++;
            }
        }
    }
SKIP:
    cout << cnt << '\n';
    return 0;
}