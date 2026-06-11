#include <bits/stdc++.h>
using namespace std;

void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}
int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    vector<int> Q(N);
    vector<int> nums(N);
    int a=0,b=0,j=0;
    for(int i=0;i<N;i++) {
        cin >> P.at(i);
    }
    for(int i=0;i<N;i++) {
        cin >> Q.at(i);
    }
    for(int i=0;i<N;i++) {
        nums.at(i) = i+1;
    }
    do{
        j++;
        if(nums == P) {
            a = j;
        }
        if(nums == Q) {
            b = j;
        }
    }while(next_permutation(nums.begin(), nums.end()));
    cout << abs(b-a) << endl;
}
