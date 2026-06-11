#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    //
    vector<vector<int>> A(3, vector<int>(3));

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> A[i][j] ;
        }
    }
    //
    int N;
    cin >> N;
    //
    vector<int> B(N);
    
    for(int i=0;i<N;i++){
        cin >> B[i];
    }
    //
    //for judge vector 
    vector<vector<int>> Judge(3, vector<int>(3));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
             Judge[i][j]=0 ;    // 0 label
        }
    }
    //
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if( B[i] == A[j][k]){
                    Judge[j][k] = 1;
                }
            }
        }
    }
    // 1
    if(((Judge[0][0]==1)&&(Judge[1][0]==1))&&(Judge[2][0]==1)){
        cout << "Yes" << endl;
    }
    else if(((Judge[0][1]==1)&&(Judge[1][1]==1))&&(Judge[2][1]==1)){
        cout << "Yes" << endl;
    }
    else if(((Judge[0][2]==1)&&(Judge[1][2]==1))&&(Judge[2][2]==1)){
        cout << "Yes" << endl;
    }
    // 2
    else if(((Judge[0][0]==1)&&(Judge[0][1]==1))&&(Judge[0][2]==1)){
        cout << "Yes" << endl;
    }
    else if(((Judge[1][0]==1)&&(Judge[1][1]==1))&&(Judge[1][2]==1)){
        cout << "Yes" << endl;
    }
    else if(((Judge[2][0]==1)&&(Judge[2][1]==1))&&(Judge[2][2]==1)){
        cout << "Yes" << endl;
    }
    // 3
    else if(((Judge[0][0]==1)&&(Judge[1][1]==1))&&(Judge[2][2]==1)){
        cout << "Yes" << endl;
    }
    else if(((Judge[2][0]==1)&&(Judge[1][1]==1))&&(Judge[0][2]==1)){
        cout << "Yes" << endl;
    }
    //
    else{
        cout << "No" << endl;
    }
    
}