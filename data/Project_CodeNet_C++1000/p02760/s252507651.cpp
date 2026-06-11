#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <math.h>
#include <stdexcept>
#include <algorithm>
#include <set>
#include <map>
#include <stdlib.h>
#include <cctype>
#include <bitset>
using namespace std;
int main(){
    int n,i,j,p,A[9];
    for(i = 0;i < 9;i++) cin >> A[i];
    cin >> n;
    for(i = 0;i < n;i++){
        cin >> p;
        for (j = 0; j < 9; j++){
            if(A[j] == p) A[j] = -1;
        }
    }
    if(A[0] == -1 && A[1] == -1 && A[2] == -1){
        cout << "Yes" << endl;
    }
    else if (A[3] == -1 && A[4] == -1 && A[5] == -1){
        cout << "Yes" << endl;
    }
    else if (A[6] == -1 && A[7] == -1 && A[8] == -1){
        cout << "Yes" << endl;
    }
    else if (A[0] == -1 && A[3] == -1 && A[6] == -1){
        cout << "Yes" << endl;
    }
    else if (A[1] == -1 && A[4] == -1 && A[7] == -1){
        cout << "Yes" << endl;
    }
    else if (A[2] == -1 && A[5] == -1 && A[8] == -1){
        cout << "Yes" << endl;
    }
    else if (A[0] == -1 && A[4] == -1 && A[8] == -1){
        cout << "Yes" << endl;
    }
    else if (A[2] == -1 && A[4] == -1 && A[6] == -1){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    //012
    //345
    //678
}