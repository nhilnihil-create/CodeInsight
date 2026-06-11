#include <iostream>
#include <vector>
#define dish_index(n) n-1
using namespace std;

int main(){
    int N; cin >> N;
    int sum = 0;

    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N-1);

    for(int i=0; i<N; i++){
        cin >> A.at(i);
    }
    for(int i=0; i<N; i++){
        cin >> B.at(i);
    }
    for(int i=0; i<N-1; i++){
        cin >> C.at(i);
    }

    for(int i=0; i<A.size(); i++){
        sum += B.at(dish_index(A.at(i)));
        if(i < A.size()-1 && 1+A.at(i) == A.at(i+1)){
            sum += C.at(dish_index(A.at(i)));
        }
    }

    cout << sum << endl;

    return 0;
}