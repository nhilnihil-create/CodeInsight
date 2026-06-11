#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<unsigned long long int> A(N);
    int i;
    unsigned long long int multi = 1;
    int zero = 0;
    for(i=0; i<N; i++){
        cin >> A.at(i);
        if(A.at(i) == 0){
            zero++;
        }
    }

    if(zero != 0){
        cout << 0 << endl;
        return 0;
    }

    for(i=0; i<N; i++){
        if(A.at(i) <= 1000000000000000000/multi){
            multi *= A.at(i);
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
        
    cout << multi << endl;
    
}