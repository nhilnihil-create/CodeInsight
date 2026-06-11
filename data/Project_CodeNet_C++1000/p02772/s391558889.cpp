#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N ;
    vector<int> A(N);
    int count = 0;
    int count_1 = 0;
    for(int i =0;i < N;i++){
        cin >> A.at(i);
        if(A.at(i) % 2 ==0){
            count++;
            if(A.at(i)%3 ==0 || A.at(i)%5 == 0){
                count_1++;
            }
        }
    }
    if(count == count_1){
        cout << "APPROVED" << endl;
    }
    else{
        cout << "DENIED" << endl;
    } 
    return 0;
}