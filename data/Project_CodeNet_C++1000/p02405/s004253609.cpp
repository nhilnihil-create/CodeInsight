#include <iostream>
#include <vector>
using namespace std;

bool is_sharp(int a, int b){
    if((a % 2 == 0 && b % 2 == 0) || (a%2 == 1 && b%2 == 1)){
        return true;
    }else{
        return false;
    }
}

int main(){
    int H, W, count = 0;
    vector<int> data_vector;
    while(1){
        cin >> H >> W;
        if (H == 0 && W == 0) break;
        data_vector.push_back(H);
        data_vector.push_back(W);
        count+=2;
    }
    for (int i = 0; i < count; i+=2) {
        H = data_vector[i];
        W = data_vector[i+1];
        for (int j=0; j<H; j++) {
            for (int k=0; k<W; k++) {
                if (is_sharp(j, k)) {
                    cout << "#";
                } else {
                    cout << ".";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}


