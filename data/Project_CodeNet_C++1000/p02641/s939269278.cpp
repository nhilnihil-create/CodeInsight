#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
using namespace std;

int arr[101];
int main(){ int x, n;
    cin >> x >> n;
    for (int i=0; i<n; i++){ int x;
        cin >> x;
        arr[x]++;
    }
    int min = 2e9, ans;
    for (int i=0; i<=102; i++){
        if(arr[i] == 0){
            if(abs(x-i) < min){
                min = abs(x-i);
                ans = i;
            }
        }
    }
    cout << ans << endl;
    return 0;
}