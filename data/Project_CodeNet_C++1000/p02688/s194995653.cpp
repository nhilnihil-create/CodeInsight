#include <iostream>
using namespace std;

bool a[101] = {0};

int main(){
    int n, k;
    cin >> n >> k;

    while(k--){
        int d; cin >> d;
        for(int i=0; i<d; i++){
            int ai; cin >> ai;
            a[ai] = 1;
        }
    }

    int res = 0;
    for(int i=1; i<=n; i++) 
        if (a[i] == 0) res++;

    cout << res << endl;
}


