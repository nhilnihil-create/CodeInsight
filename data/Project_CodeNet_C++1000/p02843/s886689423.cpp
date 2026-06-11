#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    long long X;
    cin >> X;

    int target = X % 100;
    int max_count = X / 100;
    
    int max_count_5 = min({target / 5, max_count});
    int max_count_4 = min({target / 4, max_count});
    int max_count_3 = min({target / 3, max_count});
    int max_count_2 = min({target / 2, max_count});
    int max_count_1 = min({target, max_count});

    if(target == 0){
        cout << 1 << endl;
        return 0;
    }

    for(int i=0; i<=max_count_5; i++){
        for(int j=0; j<=(max_count_4-i); j++){
        for(int k=0; k<=(max_count_3-i-j); k++){
        for(int l=0; l<=(max_count_2-i-j-k); l++){
        for(int m=0; m<=(max_count_1-i-j-k-l); m++){
            if(target == (5*i + 4*j + 3*k + 2*l + m) && max_count >= (i+j+k+l+m)){
                cout << 1 << endl;
                return 0;
            }
        }
        }
        }
        }
    }

    cout << 0 << endl;
    return 0;

}