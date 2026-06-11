#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    int H[200000];
    int maxH = 0;
    bool isOK = true;
    for (int i = 0; i < N; i++){
        cin >> H[i];
        if((maxH - 1) > H[i]){
            isOK = false;
        }
        maxH = max(maxH, H[i]);
    }
    if(isOK){
        cout << "Yes"<< endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}