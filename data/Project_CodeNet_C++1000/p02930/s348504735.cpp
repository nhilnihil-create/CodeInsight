#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <map>
#include <cstdlib>
#include <sstream>
#include <bitset>
using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector< vector<int> > vt(N, vector<int>(N, 0));
    for(int i=0; i<N; i++){
        int num=i;
        for(int j=0; j<10; j++){
            vt[i][j]=num%2;
            num/=2;
            if(num==0) break;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            for(int bi=0; bi<9; bi++){
                if(vt[i][bi]!=vt[j][bi]){
                    cout << bi+1;
                    break;
                }
            }

            if(j==N-1) cout << endl;
            else cout << ' ';
        }
    }
    

    return 0;
}