#include <bits/stdc++.h>
using namespace std;

int main(){
    float N;
    cin >> N;
    if(ceil(N/1.08) == ceil((N+1)/1.08)){
        cout << ":(" << endl;
    }else{
        cout << ceil(N/1.08) << endl;
    }
    
    return 0;
}