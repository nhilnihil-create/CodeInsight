#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>

using namespace std;


int main(){
    int N;
    cin >> N;
    int all=0;
    vector<int> as;
    for(int i=0;i<N;i++){
        long A;
        cin >> A;
        as.push_back(A);
        all ^= A;
    }
    for(int i=0;i<N;i++){
        cout << (as[i]^all) << " ";
    }

    return 0;
}
