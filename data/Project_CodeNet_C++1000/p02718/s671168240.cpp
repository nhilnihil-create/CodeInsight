#include <bits/stdc++.h>
using namespace std;
int main(void){

    int a, b, sum = 0 , cnt = 0;
    cin >> a >> b ;
    
    vector<int> vote(a);
    for(int i = 0; i < a; i++){
        cin >> vote.at(i) ;
        sum += vote.at(i);
    }

    for(int i = 0; i < a; i++){
        if(sum <= vote.at(i) * 4 * b){
            cnt++;
        }
    }

    if(cnt >= b){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}
