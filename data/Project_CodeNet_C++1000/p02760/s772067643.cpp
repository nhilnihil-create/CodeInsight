#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <map>
#include <queue>
#include <tuple>

using namespace std;

typedef long long ll;
typedef tuple<int,int,int> P;


int main(){
    int A[3][3];
    for(int i=0;i<3; i++){
        for(int j=0; j<3; j++){
            cin >> A[i][j];
        }
    }

    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int b;
        cin >> b;
        for(int i=0;i<3; i++){
            for(int j=0; j<3; j++){
                if(A[i][j]==b)A[i][j]=-1;
            }
        }
    }

    bool flag=false;
    for(int i=0; i<3; i++){
        if(A[i][0]==-1 && A[i][1]==-1 && A[i][2]==-1) flag=true;
        if(A[0][i]==-1 && A[1][i]==-1 && A[2][i]==-1) flag=true;
    }
    if(A[0][0]==-1 && A[1][1]==-1 && A[2][2]==-1) flag=true;
    if(A[2][0]==-1 && A[1][1]==-1 && A[0][2]==-1) flag=true;
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}